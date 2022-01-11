// Require the necessary discord.js classes
const { Client, Intents } = require("discord.js");
const { token } = require("./config.json");
const https = require("https")
const dataset = require("./dataset.json");
//  Basic preview since file has been added to .gitignore:
//  {
//      "token": "BOT_TOKEN"
//  }
const TotalJokes = Object.keys(dataset.joke).length
const TotalTopics = Object.keys(dataset.topic).length
const TotalPickupLines = Object.keys(dataset.pickupline).length
const TotalRoasts = Object.keys(dataset.roast).length
const TotalCompliments = Object.keys(dataset.compliment).length

// Create a new client instance
const client = new Client({
    intents: [Intents.FLAGS.GUILDS, Intents.FLAGS.GUILD_MESSAGES]
});

// When the client is ready, run this code (only once)
client.once("ready", () => {
	console.log("Ready!");
});

// Bot commands
client.on("messageCreate", (message) => {
    if (message.content === "$joke") {
        const data_index = Math.floor((Math.random() * TotalJokes) + 0);
        const data = JSON.stringify(dataset.joke[data_index]);
        message.channel.send(data);
    }

    if (message.content === "$topic") {
        const data_index = Math.floor((Math.random() * TotalTopics) + 0);
        const data = JSON.stringify(dataset.topic[data_index]);
        message.channel.send(data);
    }

    if (message.content === "$pickupline") {
        const data_index = Math.floor((Math.random() * TotalPickupLines) + 0);
        const data = JSON.stringify(dataset.pickupline[data_index]);
        message.channel.send(data);
    }

    if (message.content === "$roast") {
        const data_index = Math.floor((Math.random() * TotalRoasts) + 0);
        const data = JSON.stringify(dataset.roast[data_index]);
        message.channel.send(data);
    }

    if (message.content === "$compliment") {
        const data_index = Math.floor((Math.random() * TotalCompliments) + 0);
        const data = JSON.stringify(dataset.compliment[data_index]);
        message.channel.send(data);
    }

    if (message.content === "$quote") {
        var body = "";
        var quote = "";

        const options = {
            hostname: "zenquotes.io",
            path: "/api/random",
            method: "GET",
            headers: {
                "Content-Type": "application/json"
            }
        }

        const req = https.request(options, response => {
            console.log(`statusCode: ${response.statusCode}`)

            response.on("data", data => {
                body += data;
            })

            response.on("end", () => {
                quote = JSON.parse(body)[0]["q"];
                quote = quote.concat(" -");
                quote = quote.concat(JSON.parse(body)[0]["a"]);
                message.channel.send(quote);
            });
        })

        req.on("error", error => {
            console.log(error)
        })

        req.end()
    }
});

// Login to Discord with your client's token
client.login(token);