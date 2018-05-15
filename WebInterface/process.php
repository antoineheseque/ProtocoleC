<?php
session_start();
if(isset($_POST['submit'])){
	$_SESSION['camPosX'] = $_POST['camPosX'];
	$_SESSION['camPosY'] = $_POST['camPosY'];
	$_SESSION['camPosZ'] = $_POST['camPosZ'];

	$_SESSION['camOX'] = $_POST['camOX'];
	$_SESSION['camOY'] = $_POST['camOY'];
	$_SESSION['camOZ'] = $_POST['camOZ'];

	$_SESSION['width'] = $_POST['width'];
	$_SESSION['height'] = $_POST['height'];
}
?>

<!DOCTYPE html>
<html>
<head>
	<title>Protocole C</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="title">Protocole C: Système de Ray-Tracing.</div>
	<div class="content special">
		<form action="./process2.php" method="post">
			<fieldset>
				<legend>Objet(s)</legend>
				
				<!-- Ajouter des objets ici -->
				Type: 
				<select name="objType">
				  <option value="cube">cube</option>
				  <option value="sphere">sphere</option>
				</select>
				Position: <input type="number" name="objX" min="-100" max="100"> <input type="number" name="objY" min="-100" max="100"> <input type="number" name="objZ" min="-100" max="100">
				Taille: <input type="number" name="objSX" min="-100" max="100"> <input type="number" name="objSY" min="-100" max="100"> <input type="number" name="objSZ" min="-100" max="100">
				
				<input type="submit" name="submit" value="Afficher le Rendu">
			</fieldset>
		</form>
	</div>
</body>
</html>