<p align="center">
<img src="./ReadmeRessource2.svg" alt= "Banner" width="100%" height="auto" />
</p>

<br />

<div align="center">

<a href="https://developer.mozilla.org/fr/docs/Web/JavaScript" target="_blank" rel="noopener">
  <img src="JavaScriptBadge.svg" alt="JavaScript Badge" width="auto" height="55" />
</a>

<a href="https://nodejs.org" target="_blank" rel="noopener">
  <img src="NodejsBadge.svg" alt="Node.js Badge" width="auto" height="55" />
</a>

<a href="https://expressjs.com" target="_blank" rel="noopener">
  <img src="ExpressBadge.svg" alt="Express.js Badge" width="auto" height="55" />
</a>

</div>

<br />
<br />
<br />
<br />
<br />
<br />

<div align="center">

# Sinatra Web App

<br />

<img src="ReadmeRessource.jpg" alt="Frank Sinatra" width="200" align="center">

<br/>

*"Frank Sinatra"*
*(12 déc. 1915 - 14 may 1998)*

</div>

<br />
<br />

<div align="center">

## Summary

<br />

<h3>
  <a href="#context" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Context</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#guide" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Guide</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#more-information" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">More Information</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#download" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Download</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#credits" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Credits</kbd>
  </a>
</h3>

<br />
<br />

> **Clickable Buttons** !

</div>

<br />

<br />


<div align="center">

<h2 id="context">Context</h2>

</div>

<br />

> ---
>
> A fan website dedicated to the **American singer, actor and producer Frank Sinatra (Francis Albert Sinatra)**, one of the **most influential singers** of the **20th century** and his popularity is comparable to **"Elvis Presley, Bing Crosby or Michael Jackson"**.
> 
> Needs a backend service to feed its pages: **suggested titles**, **biographical information**, **space reserved for the administrator**.
>
> **Consequently, I developed a web application in JavaScript which allows to do these actions.**
> 
> ---

<br />

<div align="center">

<img src="ReadmeRessource1.jpg" alt="Logo JavaScript" width="200" align="center">

<br />

*"JavaScript Logo"*


<br />
<br />


<h2 id="guide">Guide</h2>

</div>

<br />

> <a href="https://developer.mozilla.org/fr/docs/Web/JavaScript" target="_blank" rel="noopener">
>  <img src="JavaScriptBadge.svg" alt="JavaScript Badge" width="250" height="50" />
></a>
>
> <br>
> <br>
>
> The application is coded in **"JavaScript"** a script coding language used for **web development**. 
> The program hosts a local server with the framework **"express"**.
> We include the framework with **"require('express')"** and **"app = express();"**.
> We define the **Host to: '0.0.0.0'** and the **Port to: "8080"**.

```javascript
const express = require('express');
const app = express();
const host = '0.0.0.0';
const port = 8080;
```
<br />
<br />
<br />

> This code can be executed by using the command on the **second terminal**: 
> 
> * **" curl `http://localhost:8080/`"**
> 
> It takes **randomly one of the 20 songs titles** of **Frank Sinatra** on the **list** and **prints it on the console**.

```javascript
const songs = [
    "Fly Me to the Moon",
    "My Way",
    "New York, New York",
    "Strangers in the Night",
    "I've Got You Under My Skin",
    "That's Life",
    "The Way You Look Tonight",
    "Come Fly with Me",
    "Night and Day",
    "All or Nothing at All",
    "Summer Wind",
    "It Was a Very Good Year",
    "Luck Be a Lady",
    "Softly, As I Leave You",
    "Somethin' Stupid",
    "My Kind of Town",
    "Young at Heart",
    "In the Wee Small Hours of the Morning",
    "Witchcraft",
    "Love and Marriage"
];

app.get('/', (req, res) => {
    const randomSong = songs[Math.floor(Math.random() * songs.length)];
    res.send(randomSong);
});
```
<br />
<br />
<br />

> These codes can be executed by using the commands on the **second terminal**: 
> 
> * **" curl `http://localhost:8080/birth_date`"**: Give Frank Sinatra's **birth date**.
> * **" curl `http://localhost:8080/birth_city`"**: Give Frank Sinatra's **city of birth**.
> * **" curl `http://localhost:8080/wives`"**: Give the list of Frank Sinatra's **wives**.
> * **" curl `http://localhost:8080/picture`"**: Redirect to a **picture** of Frank Sinatra.
> 
> In **general** it gives information about **Frank Sinatra**.

```javascript
app.get('/birth_date', (req, res) => {
    res.send('December 12, 1915');
});


app.get('/birth_city', (req, res) => {
    res.send('Hoboken, New Jersey');
});


app.get('/wives', (req, res) => {
    res.send('Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx');
});


app.get('/picture', (req, res) => {
    res.redirect('https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg');
});
```
<br />
<br />
<br />

> These codes can be executed by using the commands on the **second terminal**: 
> <br/>
> * **" curl `http://localhost:8080/public`"**: Will send Everybody can see this page.
>
> * **" curl `http://localhost:8080/protected`"**: Will send you "Not Authorized", because you are not connected as an administrator (wrong username/password).
>
> * **" curl -i `http://admin:admin@localhost:8080/protected`"**: Will give you access to the administrator space because you gave the **good** **username** and **password** which is **"admin:admin"**.
> <br/>
> 
> It sets up the security and the administrator only space in the application.
> 

```javascript
app.get('/public', (req, res) => {
  res.send('Everybody can see this page');
})

app.get('/protected', (req, res) => {
    const authHeader = req.headers.authorization;

    if (!authHeader || !authHeader.startsWith('Basic')) {
      res.set('WWW-Authenticate', 'Basic realm="Restricted Area"');
      return res.status(401).send('Not Authorized.');
    }

    const base64Credentials = authHeader.split(' ')[1]; 
    const credentials = Buffer.from(base64Credentials, 'base64').toString('utf-8'); 
    const [username, password] = credentials.split(':');

    if (username === 'admin' && password === 'admin') {
      return res.send('Welcome, authenticated client');
    }

    res.set('WWW-Authenticate', 'Basic realm="Restricted Area"');
    return res.status(401).send('Not Authorized');
});
```

<br />
<br />

> This code prints on the console the local server's host and port.
> When you run the code by using the terminal command: **"node app.js"**.
```javascript
app.listen(port, () => {
    console.log("Server Started on http://", host, ":", port);
});
```

<br />
<br />
<br />
<br />

<div align="center">

<h2 id="more-information">More Information</h2>

<br />

</div>

> ---
>
>
> **app.get( ):** Define an HTTP GET route. It tells the server what action to perform when a client sends a GET request to a specific URL.
> 
> **req:** Represents the HTTP request sent by the client.
> 
> **res:** Represents the HTTP response that your "Express application" sends back to the client. 
>
> **res.send( ):** Sends the final HTTP response to the console.
>
> **res.set( ):** Sets custom HTTP headers on the outgoing response.
>
> **res.status( ):** sets the HTTP status code for the response in Express.js. (Examples: 400, 401, 200, 404, 201).
>
> **app.listen( ):** Binds the server to a specific port and listens for incoming network requests. Officially starts the server.
>
> **console.log( ):** Print a message to the console.
>
> **buffer:** A built-in Node.js class designed to store and manipulate raw binary data such as images, files or network streams directly in memory. 
>
> **base64:** A binary-to-text encoding scheme that converts binary data into an ASCII string format, allowing files or images to be safely transferred over text-based protocols like HTTP or embedded inside JSON. 
>
>  <br>
>
> The application uses and returns several standard HTTP status codes to communicate the result of operations to the client:
> 
> * **`200 (OK)`**: Indicates that the request has succeeded. Used on routes `/`, `/birth_date`, `/birth_city`, `/wives`, `/public`, and `/protected` when authentication succeeds. 
> * **`302 (Found)`**: Indicates that the target resource resides temporarily under a different URL. Used on the `/picture` route to redirect to the official Wikipedia page.
> * **`401 (Unauthorized)`**: Indicates that the request lacks valid authentication credentials. Used on the `/protected` route when the user is not authenticated or provides wrong credentials.
> 
> ---

<br />

> [!WARNING]
> **Before:** Don't forget to open a new terminal after doing **"Node app.js"** for doing the **commands "GET (curl)"**. 

<br />
<br />

<div align="center">

<h2 id="download">Download</h2>

</div>

<br />

> ---
> #### Prerequisites:
>
> Make sure you have installed**:
> 
> <br>
> 
> <a href="https://nodejs.org" target="_blank" rel="noopener">
>  <img src="NodejsBadge.svg" alt="Node.js Badge" width="80" height="50" />
> </a>
> and
> <a href="https://expressjs.com" target="_blank" rel="noopener">
>  <img src="ExpressBadge.svg" alt="Express.js Badge" width="80" height="50" />
> </a>
>
> <br>
> <br>
> 
> If the **framework express** is **not installed** on the **case**, do the **terminal command:**
> * **" npm install express "**.
>
> **The project can be directly downloaded on GitHub.**
> 
> ---

<br />
<br />

<div align="center">

<h2 id="credits">Credits</h2>

</div>

<br />

<p align="center">

<a href="https://github.com/EliasFCS" target="_blank" rel="noopener">
  <img src="CreditBadge.svg" alt="EliasFCS Badge" width="450" height="54" />
</a>