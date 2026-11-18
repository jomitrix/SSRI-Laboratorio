const express = require('express');
const cors = require('cors');
const { mongoURL } = require('./lib');
const MongoClient = require('mongodb').MongoClient;
const ObjectId = require('mongodb').ObjectId;
const client = new MongoClient(mongoURL);

const app = express();
const port = 3003;

app.use(express.json()); 
app.use(cors());

async function getUser(id) {
    await client.connect();
    const filter = { _id: ObjectId.createFromHexString(id) };
    const user = await client.db('pwm').collection('users').findOne(filter);
    return user;
}

app.post('/user/login', async (req, res) => {
    const nome = req.body.email;
    const password = req.body.password;
    await client.connect();
    const filter = { email: nome, password: password }
    const user = await client
    .db('pwm')
    .collection('users')
    .findOne(filter);

    if (user) {
        res.json(user)
    } else {
        res.status(401).json({ error: "Credenziali Errate" })
    }
});

app.post('/user', async (req, res) => {
    const cNome = req.body.nome;
    const cCognome = req.body.cognome;
    const cEmail = req.body.email;
    const cPassword = req.body.password;
    const cFilm_preferito = req.body.film_preferito;
    //Inizio logica di controllo dei dati

    if (cNome.length < 2) {
        res.status(401).send("Nome troppo corto");
    }
    if (cCognome.length < 2) {
        res.status(401).send("Cognome troppo corto");
    }

    try {
       
        const user = {
            nome: cNome,
            cognome: cCognome,
            email: cEmail,
            password: cPassword,
            film_preferito: cFilm_preferito
        };

        await client.connect();
        const result = await client.db('pwm')
        .collection('users')
        .insertOne(user);

        await client.close();
        
        res.json(result);
        
    } catch (error) {
        if (error.code == 11000) {
            res.status(409).json({ success: false, message: "Email già in uso" });
        } else {
            res.status(500).json({ success: false, message: `Errore non gestito ${error.message}` });
        } 
    }

});

app.get('/user/:id', async (req, res) => {
    const id = req.params.id;

    const result = await getUser(id);

    if (result) {
        res.json(result)
    } else {
        res.status(404).json({ error: "Utente non trovato" })
    }

    await client.close();

})

app.put('/user/:id', async (req, res) => {
    const id = req.params.id;
    const cNome = req.body.nome;
    const cCognome = req.body.cognome;
    const cEmail = req.body.email;
    const cFilm_preferito = req.body.film_preferito;
    //Inizio logica di controllo dei dati

    if (cNome.length < 2) {
        res.status(401).send("Nome troppo corto");
    }
    if (cCognome.length < 2) {
        res.status(401).send("Cognome troppo corto");
    }

    if (cEmail == "mario.rossi@example.com") {
        res.status(409).send("Email già in uso");
    }
    try {
        //Fine logica di controllo dei dati
        await client.connect();
        const coll = client.db('pwm').collection('users');
        const result = await coll.updateOne(
            { _id: ObjectId.createFromHexString(id) },
            {
                $set: {
                    nome: cNome,
                    cognome: cCognome,
                    email: cEmail,
                    film_preferito: cFilm_preferito
                }
            });
        res.json(result);
        await client.close();
    } catch (error) {
        if (error.code == 11000) {
            res.status(409).json({ success: false, message: "Email già in uso" });
        } else {
            res.status(500).json({ success: false, message: error.message });

        }
    }
})

app.patch('/user/:id', async (req, res) => {
    const id = req.params.id;
    const { nome, cognome, email, film_preferito } = req.body;

    await client.connect();
    const result = await client.db('pwm')
    .collection('users')
    .updateOne(
        { _id: ObjectId.createFromHexString(id) },
        { $set: { nome, cognome, email, film_preferito } }
    );

    if (!result.matchedCount) {
        return res.status(404).send({ status: "error", message: "Utente non trovato" });
    }

    res.send({ status: "success", message: "Utente aggiornato" });
});

app.delete('/user/:id', async (req, res) => {
    const id = req.params.id;
    await client.connect();
    const result = await client.db('pwm')
    .collection('users')
    .deleteOne({_id: ObjectId.createFromHexString(id)})
    
    res.json(result);
});

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})