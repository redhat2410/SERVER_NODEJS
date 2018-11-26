var net = require('net');
var ip = require('ip');
var PORT = 3000;

var listUser = [];
var tcp_server = net.createServer(function(socket){
    //Nhap user_name luu user_name va phan hoi lai
    socket.on('data', function(message){
        // doc message tu client gui toi server
        console.log(message.toString());
        // luu account cua client vao danh sach
        listUser.push(message);
        // gui phan hoi message lai cho clien
        socket.write("Hello " + message);
    });
});

tcp_server.listen(process.env.PORT || PORT);
console.log("Server dang chay o dia chi: " + ip.address()+ ":" + PORT);