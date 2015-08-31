// WebSocket Server

var WebSocketServer = require('ws').Server,
    wss = new WebSocketServer({ port: 8000 });

var wsi = null;

wss.on('connection', function connection(ws) {
  wsi = ws;

  ws.on('message', function incoming(message) {
    console.log('WebSocket received: %s', message);
  });

  console.log('WebSocket server running on port 8000');
});

// REST Server

var express = require('express'),
    app = express(),
    bodyParser = require('body-parser');

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.post('/send', function(req, res) {
  console.log('Received:');
  console.log(req.body);
  wsi.send(JSON.stringify(req.body));
  res.end('{"success":true}');
});

var server = app.listen(8001, function() {
  console.log('REST server listening on port 8001')
});
