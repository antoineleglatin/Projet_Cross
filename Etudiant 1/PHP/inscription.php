
		<?php

				// Connexion à la base de données 
				$db_username = 'azerty';
				$db_password = 'azerty';
				$db_name     = 'Projet_Cross';
				$db_host     = 'localhost';
				$db = mysqli_connect($db_host, $db_username, $db_password,$db_name)
					or die('could not connect to database');

				$Nom = $_POST['Nom'];
				$Prenom = $_POST['Prenom'];
				$Mail = $_POST['Mail'];
				$Mdp = $_POST['Mdp'];
				$Classe = $_POST['Classe'];

			if ($db) {           
				$sql = "INSERT INTO Utilisateur(IdUtilisateur, Nom, Prenom, Mail, Mdp, Admin, Classe) VALUES('','$Nom','$Prenom','$Mail','$Mdp','','$Classe')";
				
				// Exécution de la requête 
				$resultat = mysqli_query($db, $sql); 
				if ($resultat == FALSE) { 
					echo "Echec de l'inscription.<br />"; 
				} 
				else { 
					echo "Personne enregistrée.<br />"; 
					header('Location: 127.0.0.1/accueil_connexion.php');
				} 

			} 
			else { 
			printf('Erreur %d : %s.<br/>',mysqli_connect_errno(),mysqli_connect_error()); 
			} 

		?>

