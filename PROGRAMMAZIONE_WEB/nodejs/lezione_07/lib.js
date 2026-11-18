const api_key = 'YOUR_TMDB_API_KEY';
const mongoURL = process.env.MONGO_URI || "mongodb+srv://<USERNAME>:<PASSWORD>@<CLUSTER_URL>/?retryWrites=true&w=majority";

module.exports = {
    mongoURL
};