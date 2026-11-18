const express = require('express');
const cors = require('cors');
const MongoClient = require('mongodb').MongoClient; //importiamo solo il client da mongodb
const ObjectId = require('mongodb').ObjectId;
const app = express();
const port = 3000;

const mongoURL = process.env.MONGO_URI || "mongodb+srv://<USERNAME>:<PASSWORD>@<CLUSTER_URL>/?retryWrites=true&w=majority";

app.use(express.json()); 
app.use(cors());



app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})