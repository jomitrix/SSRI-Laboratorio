const express = require('express')
const app = express()
const port = 3000

app.use(express.json()); // middleware e funzionano a catena prima di elaborare la risposta API

app.post("/user", (req, res) => {
    const nome = req.body.nome;
    const cognome = req.body.cognome;
    const email = req.body.email;
    
    if (nome.length < 2) {
        res.status(400).send("Nome troppo corto");
        return;
    }

    if (email == "mario.rossi@example.com") {
        res.status(409).send("Email già in uso");
        return;
    }

    res.send(req.body);
});

app.delete("/user/:id", (req, res) => {
    const id = req.params.id;
    res.send(`${id} DELETED`);
});

app.post("/login", (req, res) => {
    const user = req.body.user;
    const password = req.body.password;

    if (user == "Mario") {
        res.send("OK");
    } else {
        res.status(401).send("KO");
    }
});

app.get("/user/:id", (req, res) => {
    const id = req.params.id;
    res.send(`${id}`);
});

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})