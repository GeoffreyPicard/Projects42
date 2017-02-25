 var video = document.getElementById('video');

if(navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    navigator.mediaDevices.getUserMedia({ video: true }).then(function(stream) {
        video.src = window.URL.createObjectURL(stream);
        video.play();
    });
}

snap.addEventListener('click', function(ev){
       photo = document.getElementById('choix').value
       if (photo == "Empty")
       {
          alert("You must choose an image before snap")
          exit()
       }
      takepicture(readData);
    ev.preventDefault();
  }, false);

var i = -250

function takepicture(callback) {

  var canvas = document.getElementById('canvas')
  var context = canvas.getContext('2d')
  context.drawImage(video, 0, 0, 300, 250);
  var data = canvas.toDataURL('image/png')

  var xmlhttp = new XMLHttpRequest()

  xmlhttp.onreadystatechange = function () {
    if (xmlhttp.readyState === 4)
      callback(xmlhttp.responseText)
  }
  xmlhttp.open("POST","sendphoto.php");
xmlhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
  xmlhttp.send("image=" + data + "&png=" + photo)
};

function readData(sData)
{
  var ctx = document.getElementById('galerie').getContext('2d');
  ima = sData
  var img = new Image();
  img.src = sData

  img.onload = function(){
    if (i == 750)
      i = -250
    i += 250
  ctx.drawImage(img, 0, i, 250, 250);
}

var tof = document.getElementById("myFile").files[0];

function choix() {
  photo = document.getElementById('choix').value
}
}

function upload()
{

  photo = document.getElementById('choix').value
       if (photo == "Empty")
       {
          alert("You must choose an image before snap")
          exit()
       }
  var canvas = document.getElementById('canvas')
  var context = canvas.getContext('2d')
  


  var preview = document.querySelector('#preview');
  var files   = document.querySelector('input[type=file]').files;

  function readAndPreview(file) {

    // Make sure `file.name` matches our extensions criteria
    if ( /\.(jpe?g|png|gif)$/i.test(file.name) ) {
      var reader = new FileReader();

      reader.addEventListener("load", function () {
        var image = new Image();
        image.height = 100;
        image.title = file.name;
        image.src = this.result;

          context.drawImage(image, 0, 0, 300, 250);
          var data = canvas.toDataURL('image/png');
          var xmlhttp = new XMLHttpRequest()

        xmlhttp.onreadystatechange = function () {
          if (xmlhttp.readyState === 4)
             readData(xmlhttp.responseText)
             }
          xmlhttp.open("POST","sendphoto.php");
          xmlhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
          xmlhttp.send("image=" + data + "&png=" + photo)
      }, false);

      reader.readAsDataURL(file);
    }

  }
  if (files) {
    [].forEach.call(files, readAndPreview);
  }

}






  