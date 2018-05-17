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
	$_SESSION['frames'] = $_POST['frames'];
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
				<select name="objType" value="sph" required>
				  <option value="cub">Cube</option>
				  <option value="sph">Sphere</option>
				  <option value="pla">Plan</option>
				</select>
				Position: <input type="number" name="objX" value="0" min="-100" max="100" required> <input type="number" name="objY" value="2" min="-100" max="100" required> <input type="number" name="objZ" value="5" min="-100" max="100" required>
				Taille: <input type="number" name="objSX" value="2" min="-100" max="100" required> <input type="number" name="objSY" value="2" min="-100" max="100" required> <input type="number" name="objSZ" value="2" min="-100" max="100" required>
				
				<input type="submit" name="submit" value="Afficher le Rendu">
			</fieldset>
		</form>
	</div>
</body>
</html>