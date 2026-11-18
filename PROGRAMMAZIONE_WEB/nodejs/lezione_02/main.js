const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
    res.send('Hello World Mario!');
})

app.get('/user/:id/fav', (req, res) => { 
    const id = req.params.id;
    res.send(`Preferiti utente ${id}:`);
})

app.get('/user/:id/film/:film', (req, res) => { // più paramentri nello stesso URI
    const id = req.params.id;
    const film = req.params.film;
    res.send(`Dati utente: ${id} <br> Film: ${film}`);
})

app.get('/user/:id', (req, res) => { //:id prende una variabile id
    const id = req.params.id;
    const page = req.query.page;
    const q = req.query.q;

    if (id >= 0 && id <= 30) { //limito le richieste ma devo gestire i casi non validi altrimenti do problemi al backhand
        let lang = req.query.lang; // si presume venga passato come parametro una lang e la ricevo così

        // se il parametro non viene passato NON è ok anche se in questo esempio funziona
        // se si lavora con questo parametro che è undefined muore il backhand e crasha
        // si può gestire con un check

        if (lang == undefined) {
            //res.status(400).send("Parametro Lingua assente");
            //return; //esco dal codice sennò invia anche l'altro pacchetto
            // se il parametro non è passato si può anche gestire mettendo una lingua di default

            lang = "en";
        }

        //res.send(`Dati utente: ${id} <br> Parametri: Language: ${lang}`);

        // Possibilità di restituire un JSON!
        const risposta =
        {
            identificatore: id,
            stato: "OK",
            parametri: {
                lingua: lang,
                query: q,
                pagina: page
            }
        };
        res.json(risposta);
        
    } else {
        res.status(404).send(`Utente NON trovato.`); // mando comunque qualcosa ma è un errore (404 risorsa non trovata)
    }
})

// esercizio
app.get('/movie/:id/', (req, res) => { // più paramentri nello stesso URI
    const id = req.params.id;
    const risposta = 
    {
        titolo: "Film " + id,
        uscita: "12-9-2004",
        attori: [
            {
                nome: "Paolo Rossi",
                known_for: "acting" 
            },
            {
                nome: "Mario Neri",
                known_for: "acting" 
            }
        ]
    };

    res.json(risposta);
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})