const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
    res.send('Hello World Mario!');
})

app.get('/pwm', (req, res) => {
    res.send('Hello World 2!');
})

app.get('/pwm/lezione', (req, res) => {
    res.send('Lezione!');
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})