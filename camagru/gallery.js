function uplike(image)
{

	var xmlhttp = new XMLHttpRequest()
 	xmlhttp.onreadystatechange = function () {
    if (xmlhttp.readyState === 4)
      console.log('ok')
  }
xmlhttp.open("POST", "uplike.php");
xmlhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
xmlhttp.send()
}