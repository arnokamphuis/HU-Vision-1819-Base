README.txt voor FaceMinMin

Het programma is bedoeld om d.m.v. het meegeleverde ExternalDLL.dll-bestand studenten kennis bij te brengen over het gebruik van computer vision algoritmen. 
In dit programma voert men één afbeelding van een biometrische pasfoto in. Hier zal vervolgens aan de hand van de uitvoer-opties een juiste actie over uitgevoerd worden. 

Hieronder volgt een schematische weergave van het programma:

____________________________________________________________________________________________________
|			 									    |
|	Menu	| Opties |									    |
|___________________________________________________________________________________________________|
|												    |
|												    |
|	 _________________________	 _________    __________	 _________________________  |	
|	|1. mainPictureBox	  |	|2.	  |  |2.	|	|3. resultPictureBox	  | |		
|	|			  |	|	  |  |		|	|			  | |
|	|			  |	|	  |  |		|	|			  | |	
|	|			  |	|	  |  |		|	|			  | |		
|	|			  |	|	  |  |		|	|			  | |		
|	|			  |	|	  |  |		|	|			  | |		
|	|			  |	 ---------    ----------	|			  | |
|	|			  |	 ---------    ----------	|			  | |	
|	|			  |	|2.	  |  |2.	|	|			  | |		
|	|			  |	|	  |  |		|	|			  | |		
|	|			  |	|	  |  |		|	|			  | |		
|	|			  |	|	  |  |		|	|			  | |	
|	|			  |	|	  |  |		|	|			  | |	
|	|_________________________|	|_________|  |__________|	|_________________________| |		
|												    |		
|	 ____________________________________________________________	 _________________________  |	
|	|4. feedbackTextBox					     |	|5. Uitvoeropties	  | |	
|	|							     |	|			  | |		
|	|							     |	|			  | |		
|	|							     |	|  () Herkennen		  | |		
|	|							     |	|			  | |		
|	|							     |	|  () Inscannen		  | |		
|	|							     |	|			  | |		
|	|							     |	|  () Sequentie herkennen | |
|	|							     |	|			  | |				
|	|							     |	|	naam/.xml-file:	  | |		
|	|							     |	|	 _______________  | |		
|	|							     |	|	|_______________| | |		
|	|							     |	|_________________________| |		
|	|____________________________________________________________|	 _________________________  |
|									|6. Uitvoeren		  | |		
|									|_________________________| |
|___________________________________________________________________________________________________|


1. mainPictureBox
	Door hier double-click op te doen opent zich een venster waarmee je een invoer afbeelding kan selecteren.

2. progressPictureBox(es)
	In deze boxes staat een tussenstap van het programma weergegeven als een vorm van tussentijdse feedback
	Het is mogelijk om door een double-click het scherm te vergroten. Of door een right-click meerdere opties 
	erop uit te kunnen voeren. Zoals het opslaan van de afbeelding.

3. resultPictureBox
	In deze picture box wordt, bij het selecteren van de uitvoer-optie "Herkennen" of "Sequentie herkennen" de
	afbeelding, met de meeste vergelijkenis, uit de testset weergegeven. Net als bij "2. progressPictureBox(es)" kan hier dmv.  
	een right-click een serie handelingen mee gedaan worden.

4. feedbackTextBox
	d.m.v. de feedbackTextBox wordt de gebruiker van de applicatie op de hoogte gebracht van bepaalde informatie die tijdens de 
	uitvoer van het programma gegeven wordt.

5. Uitvoer-opties
	Er zijn momenteel 3 verschillende opties: "Herkennen", "Inscannen" en "Sequentie herkennen".
	
	Bij het selecteren van "Herkennen" zal de afbeelding in 1. als invoer gebruikt worden voor de algoritmen. Vervolgens
	zal de afbeelding gerepresenteerd worden door 16 parameters. De afbeelding uit de testset met de meeste overeenkomsten
	zal hierna weergegeven worden in 3. en in 4. zal de opgegeven naam van de herkende persoon weergegeven worden, evenzo als
	het gemiddelde verschil tussen de parameters.
	
	Bij het selecteren van "Inscannen" zal er verzocht worden om een naam van de persoon op de foto mee te geven, als
	deze niet meegegeven wordt zal het de naam "<unknown>" krijgen. Vervolgens wordt er een poging gedaan worden om alle
	gezichtskenmerken uit de afbeelding te halen en dit vervolgens om te zetten in een representatie van 16 parameters.
	Als deze parameters allemaal succesvol berekend zijn zullen deze vervolgens in de TestSet.xml-file gezet worden, met
	de meegegeven naam. Ook wordt de gebruikte afbeelding als .png-bestand opgeslagen in de directory "TestSet Images".
	
	De laatste optie is "Sequentie herkennen" dit is een optie om in een keer meerdere foto's te herkennen, dit kan 
	door een .xml bestand te maken en daarin de paden naar de foto's te zetten. Dit kan als volgt:
		<?xml version="1.0" encoding="utf-8"?>
		<SeqFile xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
			<imgpath>C:\Users\Alexander\Dropbox\Onderzoekssemester - Face recognition\TestA5.jpg</imgpath>
			<imgpath>C:\Users\Alexander\Dropbox\Onderzoekssemester - Face recognition\TestA4.jpg</imgpath>
		</SeqFile>
	Dit bestand kan geselecteerd worden door een double-click te doen om het TextBox met het label: ".xml-file:" of door 
	het handmatig in deze TextBoxin te voeren

	Bij het uitvoeren hiervan hoeft er geen foto in de "mainPictureBox" gedaan te worden.
	Tijdens het uitvoeren van deze optie zullen alle afbeeldingen 1-voor-1 door het programma heen lopen, dus wordt de
	afbeelding met de meeste vergelijkenis maar even weergegeven. Wel zal er in 4. weergegeven worden wat de naam is met de 
	beste match.

6. Uitvoeren-knop
	Bij het drukken op deze knop zal er allereerst gekeken worden op er een Uitvoer-optie geselecteerd is (5.) en vervolgens
	wordt het programma gestart volgens deze optie.


In de menubalk staan ook nog twee tabs: "Menu" en "Opties".
 
In "Menu" worden de opties gegeven om een afbeelding te selecteren voor 1. of om deze afbeelding op te slaan. Ook staat er een 
optie bij genaamd "Afbeeldingen Opslaan" deze werkt op dit moment niet.

In "Opties" zitten meer functionaliteiten verscholen, het is namelijk mogelijk om via "Algoritme opties" aan te geven welke 
algoritmen er gebruikt worden bij het uitvoeren van het programma, de code van de student of de meegeleverde code. Standaard
staat dit alles op het uitvoeren van de meegeleverde code.
Ook is er de optie om via "Testset beheren" een ander testset-bestand (.xml) te selecteren, of om huidige informatie uit de testset
aan te passen dan wel te verwijderen. Het gaat hier om de data: Naam, Parameters (16 doubles ';'-seperated), ImagePath
Als laatst is er een "Help"-optie, dit opent deze README.txt

