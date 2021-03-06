<?php
session_start();

function AddSphere($posX, $posY, $posZ, $radius, $colR, $colG, $colB){
	$_SESSION['objList'][] = "sph;" . $posX . ";" . $posY . ";" . $posZ . ";" . $radius . ";" . $colR . ";" . $colG . ";" . $colB . "\n";
	$_SESSION['objCount'] = count($_SESSION['objList'])+1;
}
function AddTriangle($posXa, $posYa, $posZa, $posXb, $posYb, $posZb, $posXc, $posYc, $posZc, $colR, $colG, $colB){
	$_SESSION['objList'][] = "tri;" . $posXa . ";" . $posYa . ";" . $posZa . ";". $posXb . ";" . $posYb . ";" . $posZb . ";". $posXc . ";" . $posYc . ";" . $posZc . ";" . $colR . ";" . $colG . ";" . $colB . "\n";
}
function AddQuadri($posXa, $posYa, $posZa, $posXb, $posYb, $posZb, $posXc, $posYc, $posZc, $posXd, $posYd, $posZd, $colR, $colG, $colB){
	$_SESSION['objList'][] = "qua;" . $posXa . ";" . $posYa . ";" . $posZa . ";". $posXb . ";" . $posYb . ";" . $posZb . ";". $posXc . ";" . $posYc . ";" . $posZc . ";" . $posXd . ";" . $posYd . ";" . $posZd . ";" . $colR . ";" . $colG . ";" . $colB . "\n";
}
function AddLight($type, $intensity, $posX, $posY, $posZ){
	$_SESSION['lightList'][] = $type . ";" . $intensity . ";" . $posX . ";" . $posY . ";" . $posZ . "\n";
	$_SESSION['lightCount'] = count($_SESSION['lightList'])+1;
}

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

	if(!isset($_SESSION['objCount']))
		$_SESSION['objCount'] = 0;
	if(!isset($_SESSION['lightCount']))
		$_SESSION['lightCount'] = 0;

	if(empty($_SESSION['lightList'])){
		AddLight("all", 2, 5, 20, 10);
		AddLight("nor", 1, 0, 0, 0);
		AddSphere(3,2,12,2,150,0,0);
		AddSphere(-10,1,20,1,0,150,0);
		AddSphere(0,2.3,10,2,0,0,150);
		header("Location: process.php");
	}
}

if(isset($_POST['submitSphere'])){
		AddSphere($_POST['posX'], $_POST['posY'], $_POST['posZ'], $_POST['radius'], $_POST['colR'], $_POST['colG'], $_POST['colB']);
}

if(isset($_POST['submitTriangle'])){
		AddTriangle($_POST['posTriXa'], $_POST['posTriYa'], $_POST['posTriZa'], $_POST['posTriXb'], $_POST['posTriYb'], $_POST['posTriZb'], $_POST['posTriXc'], $_POST['posTriYc'], $_POST['posTriZc'], $_POST['colR'], $_POST['colG'], $_POST['colB']);
		$_SESSION['objCount'] = count($_SESSION['objList'])+1;
}

if(isset($_POST['submitQuadri'])){
		AddQuadri($_POST['posQuadXa'], $_POST['posQuadYa'], $_POST['posQuadZa'], $_POST['posQuadXb'], $_POST['posQuadYb'], $_POST['posQuadZb'], $_POST['posQuadXc'], $_POST['posQuadYc'], $_POST['posQuadZc'], $_POST['posQuadXd'], $_POST['posQuadYd'], $_POST['posQuadZd'], $_POST['colR'], $_POST['colG'], $_POST['colB']);
		$_SESSION['objCount'] = count($_SESSION['objList'])+1;
}

if(isset($_POST['submitLight'])){
		AddLight($_POST['type'], $_POST['intensity'] , $_POST['posLumX'], $_POST['posLumY'], $_POST['posLumZ']);
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
						echo $_SESSION['objList'][$i] . "<form action=\"./removeObj.php\" method=\"post\"><input type=\"hidden\" name=\"index\" value=\"" . $i . "\"><input type=\"submit\" name=\"submit\" value=\"Supprimer l'objet\"></form>". "<br>";
					}
				}
			?>
		</fieldset><br>
		<fieldset>
			<legend>Source(s) lumineuse(s)</legend>
			<?php
				for($i = 0; $i < $_SESSION['lightCount']; $i++){
					if(!empty($_SESSION['lightList'][$i])){
						echo $_SESSION['lightList'][$i] . "<form action=\"./removeLight.php\" method=\"post\"><input type=\"hidden\" name=\"index\" value=\"" . $i . "\"><input type=\"submit\" name=\"submit\" value=\"Supprimer la source\"></form>" . "<br>";
					}
				}
			?>
		</fieldset>
		<br>
		<embed src="waiting.mp3" autostart="true" loop="false" hidden="true"></embed>
		<form action="./process.php" method="post">
			<fieldset>
				<legend>Ajouter une source lumineuse</legend>
				<label for="type">Type de source</label><br />
				<select name="type" id="pays">
						<option value="spe">Speculaire</option>
						<option value="nor">Normale</option>
						<option value="all">Tout</option>
				</select>
				Position de la source :
				<input type="number" name="posLumX" value="-5" min="-1000" max="1000" required> <input type="number" name="posLumY" value="10" min="-1000" max="1000" required> <input type="number" name="posLumZ" value="10" min="-1000" max="1000" required><br><br>
				Intensité de la source :
				<input type="number" name="intensity" value="2" min="0.1" max="6" step="0.1" required>
				<div class="submit"><input type="submit" name="submitLight" value="Ajouter une source lumineuse"></div>
			</fieldset><br>
			<fieldset>
				<legend>Ajouter une Sphère</legend>
				Position de la sphère :
				<input type="number" name="posX" value="0" min="-1000" max="1000" required> <input type="number" name="posY" value="2" min="-1000" max="1000" required> <input type="number" name="posZ" value="10" min="-1000" max="1000" required><br><br>
				Rayon : <input type="number" name="radius" value="2" min=".5" max="50" step="0.5" required><br>
				<br>Couleur (RGB) :
				<input type="number" name="colR" value="0" min="-0" max="255" required> <input type="number" name="colG" value="2" min="-0" max="255" required> <input type="number" name="colB" value="10" min="-0" max="255" required>

				<div class="submit"><input type="submit" name="submitSphere" value="Ajouter une sphère"></div>
			</fieldset><br>
			<!--<fieldset>
				<legend>Ajouter un Triangle</legend>
				Position du point n°1 du triangle :
				<input type="number" name="posTriXa" value="0" min="-1000" max="1000" required> <input type="number" name="posTriYa" value="2" min="-1000" max="1000" required> <input type="number" name="posTriZa" value="10" min="-1000" max="1000" required><br><br>
				Position du point n°2 du triangle :
				<input type="number" name="posTriXb" value="0" min="-1000" max="1000" required> <input type="number" name="posTriYb" value="2" min="-1000" max="1000" required> <input type="number" name="posTriZb" value="10" min="-1000" max="1000" required><br><br>
				Position du point n°3 du triangle :
				<input type="number" name="posTriXc" value="0" min="-1000" max="1000" required> <input type="number" name="posTriYc" value="2" min="-1000" max="1000" required> <input type="number" name="posTriZc" value="10" min="-1000" max="1000" required><br><br>
				<br>Couleur (RGB) :
				<input type="number" name="colTriR" value="0" min="-0" max="255" required> <input type="number" name="colTriG" value="2" min="-0" max="255" required> <input type="number" name="colTriB" value="10" min="-0" max="255" required>
				<div class="submit"><input type="submit" name="submitTriangle" value="Ajouter un triangle"></div>
			</fieldset><br>
			<fieldset>
				<legend>Ajouter un Quadrilatère</legend>
				Position du point n°1 du quadrilatère :
				<input type="number" name="posQuadXa" value="0" min="-1000" max="1000" required> <input type="number" name="posQuadYa" value="2" min="-1000" max="1000" required> <input type="number" name="posQuadZa" value="10" min="-1000" max="1000" required><br><br>
				Position du point n°2 du quadrilatère :
				<input type="number" name="posQuadXb" value="0" min="-1000" max="1000" required> <input type="number" name="posQuadYb" value="2" min="-1000" max="1000" required> <input type="number" name="posQuadZb" value="10" min="-1000" max="1000" required><br><br>
				Position du point n°3 du quadrilatère :
				<input type="number" name="posQuadXc" value="0" min="-1000" max="1000" required> <input type="number" name="posQuadYc" value="2" min="-1000" max="1000" required> <input type="number" name="posQuadZc" value="10" min="-1000" max="1000" required><br><br>
				Position du point n°4 du quadrilatère :
				<input type="number" name="posQuadXd" value="0" min="-1000" max="1000" required> <input type="number" name="posQuadYd" value="2" min="-1000" max="1000" required> <input type="number" name="posQuadZd" value="10" min="-1000" max="1000" required><br><br>
				<br>Couleur (RGB) :
				<input type="number" name="colQuadR" value="0" min="-0" max="255" required> <input type="number" name="colQuadG" value="2" min="-0" max="255" required> <input type="number" name="colQuadB" value="10" min="-0" max="255" required>

				<div class="submit"><input type="submit" name="submitQuadri" value="Ajouter un quadrilatère"></div>
			</fieldset>-->
			<br>
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
