const PORT = 3484;

var http = require('http');
var socketio = require('socket.io');
var ip = require('ip');
var app = http.createServer();
var io = socketio(app);
app.listen(PORT);

console.log("Server nodejs chay tai dia chi: "+ip.address()+":"+PORT);

function ParseJson(jsondata){
    try{
        return JSON.parse(jsondata);
    }
    catch(error){
        return null;
    }
}

function sendTime(){
    var json = {
        data : "hello world",
        esp8266: 12,
        sopi: 3.14,
        time: new Date()
    }
    io.sockets.emit('atime', json);
}

io.on('connection', function(socket){
    console.log("Connected");
    socket.emit('welcome',{
        message: 'Connected !!!!'
    });

    socket.on('connection', function(message){
        console.log(message);
    });

    socket.on('atime', function(data){
        sendTime();
        console.log(data);
    });

    socket.on('arduino', function(data){
        io.sockets.emit('arduino', {message: 'R0'});
        console.log(data);
    });
});