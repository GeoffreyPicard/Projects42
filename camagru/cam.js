 var video = document.getElementById('video');

if(navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    navigator.mediaDevices.getUserMedia({ video: true }).then(function(stream) {
        video.src = window.URL.createObjectURL(stream);
        video.play();
    });
}

var canvas = document.getElementById('canvas');
var context = canvas.getContext('2d');
var video = document.getElementById('video');

var data = canvas.toDataURL();



document.getElementById("snap").addEventListener("click", function() {
  var xmlhttp = new XMLHttpRequest()

  xmlhttp.onreadystatechange = function () {
    if (xmlhttp.readyState === 4)
     console.log(xmlhttp.responseText)
  }
xmlhttp.open("POST","sendphoto.php");
xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
xmlhttp.send("image=" + data);
  context.drawImage(video, 0, 0, 300, 300);
});






// Converts canvas to an image
function convertCanvasToImage(video) {
  var image = new Image();
  image.src = canvas.toDataURL("image/png");
  return image;
}

    
  