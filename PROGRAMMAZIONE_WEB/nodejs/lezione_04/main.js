const express = require('express');
const cors = require('cors');
const MongoClient = require('mongodb').MongoClient; //importiamo solo il client da mongodb
const ObjectId = require('mongodb').ObjectId;
const app = express();
const port = 3000;

const mongoURL = process.env.MONGO_URI || "mongodb+srv://<USERNAME>:<PASSWORD>@<CLUSTER_URL>/?retryWrites=true&w=majority";

app.use(express.json()); 
app.use(cors());

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

app.get("/movies", async (req, res) => {
    const {year, rated} = req.query;
    const filter = {};
    if (year !== undefined) filter.year = parseInt(year);
    if (rated !== undefined) filter.rated = rated;

    const client = await MongoClient.connect(mongoURL);
    const coll = client.db("sample_mflix").collection("movies");
    const cursor = coll.find(filter);
    const result = await cursor.toArray();
    await client.close();

    res.json(result);
});

app.get("/movies/:id", async (req, res) => {
    const { id } = req.params;

    const client = await MongoClient.connect(mongoURL);
    const coll = client.db("sample_mflix").collection("movies");
    const cursor = coll.find(new ObjectId(id));
    const result = await cursor.toArray();
    await client.close();

    res.json(result);
});

app.get("/movies/year/:year", async (req, res) => {
    const { year } = req.params;
    year;

    const client = await MongoClient.connect(mongoURL);
    const coll = client.db("sample_mflix").collection("movies");
    const cursor = coll.find( {year: parseInt(year)} );
    const result = await cursor.toArray();
    await client.close();

    res.json(result);
});



app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})