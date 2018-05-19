<?php
session_start();
if(isset($_POST['submit'])){
	$_SESSION['camPosX'] = $_POST['camPosX'];
	$_SESSION['camPosY'] = $_POST['camPosY'];
	$_SESSION['camPosZ'] = $_POST['camPosZ'];

	$_SESSION['camOX'] = $_POST['camOX'];
	$_SESSION['camOY'] = $_POST['camOY'];
	$_SESSION['camOZ'] = $_POST['camOZ'];

	$_SESSION['addLight'] = $_POST['addLight'];
	$_SESSION['lightPosX'] = $_POST['lightPosX'];
	$_SESSION['lightPosY'] = $_POST['lightPosY'];
	$_SESSION['lightPosZ'] = $_POST['lightPosZ'];

	$_SESSION['width'] = $_POST['width'];
	$_SESSION['height'] = $_POST['height'];
	$_SESSION['frames'] = $_POST['frames'];

	if(!isset($_SESSION['objCount']))
		$_SESSION['objCount'] = 0;
}

if(isset($_POST['submitSphere'])){
		AddSphere($_POST['posX'], $_POST['posY'], $_POST['posZ'], $_POST['radius'], $_POST['colR'], $_POST['colG'], $_POST['colB']);
		$_SESSION['objCount'] = count($_SESSION['objList'])+1;
}

function AddSphere($posX, $posY, $posZ, $radius, $colR, $colG, $colB){
	$_SESSION['objList'][] = "sph;" . $posX . ";" . $posY . ";" . $posZ . ";" . $radius . ";" . $colR . ";" . $colG . ";" . $colB . "\n";
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
	<div class="content">
		<fieldset>
			<legend>Objet(s)</legend>
			<?php
				for($i = 0; $i < $_SESSION['objCount']; $i++){
					if(!empty($_SESSION['objList'][$i])){
						echo $_SESSION['objList'][$i] . "<form action=\"./removeObj.php\" method=\"post\"><input type=\"hidden\" name=\"index\" value=\"" . $i . "\"><input type=\"submit\" name=\"submit\" value=\"Supprimer l'objet\"></form>";
					}
				}
			?>
		</fieldset>
		<br>

		<form action="./process.php" method="post">
			<fieldset>
				<legend>Ajouter une Sphère</legend>
				Position de la sphère : 
				<input type="number" name="posX" value="0" min="-1000" max="1000" required> <input type="number" name="posY" value="2" min="-1000" max="1000" required> <input type="number" name="posZ" value="10" min="-1000" max="1000" required><br><br>
				Rayon : <input type="number" name="radius" value="2" min=".5" max="50" step="0.5" required><br>
				<br>Couleur (RGB) : 
				<input type="number" name="colR" value="0" min="-0" max="255" required> <input type="number" name="colG" value="2" min="-0" max="255" required> <input type="number" name="colB" value="10" min="-0" max="255" required>

				<div class="submit"><input type="submit" name="submitSphere" value="Ajouter une sphère"></div>
			</fieldset>
		</form>

		<form action="./process2.php" method="post"><input type="submit" name="submit" value="Afficher le Rendu"></form>
		<!--
		<form action="./process2.php" method="post">
			<fieldset>
				<legend>Objet(s)</legend>

				Ajouter des objets ici
				Type:
				<select name="objType" value="sph" required>
				  <option value="cub">Cube</option>
				  <option value="sph">Sphere</option>
				  <option value="pla">Plan</option>
				</select>
				Position: <input type="number" name="objX" value="0" min="-100" max="100" required> <input type="number" name="objY" value="2" min="-100" max="100" required> <input type="number" name="objZ" value="5" min="-100" max="100" required>
				Taille: <input type="number" name="objSX" value="2" min="-100" max="100" required> <input type="number" name="objSY" value="2" min="-100" max="100" required> <input type="number" name="objSZ" value="2" min="-100" max="100" required>
				Color: <input type="number" name="colorR" value="255" min="0" max="255" required> <input type="number" name="colorG" value="2" min="0" max="255" required> <input type="number" name="colorB" value="128" min="0" max="255" required>
				<input type="submit" name="submit" value="Afficher le Rendu">
			</fieldset>
		</form>
	-->
	</div>
</body>
</html>
