<!-- MarkdownTOC -->

- 1. Implementatieplan
	- 1.1. Namen en datum
	- 1.2. Doel
	- 1.3. Methoden
		- 1.3.1. Sobel
		- 1.3.2. Canny
		- 1.3.3. Deriche
		- 1.3.4. Differential
		- 1.3.5. Prewitt
		- 1.3.6. Roberts cross
	- 1.4. Keuze
	- 1.5. Implementatie
	- 1.6. Keuze
	- 1.7. Implementatie
	- 1.8. Evaluatie

<!-- /MarkdownTOC -->
# 1. Implementatieplan

## 1.1. Namen en datum

16 mei 2018

    • Carlos van Rooijen
    • Jordan Ramirez

## 1.2. Doel
Het doel is om belangrijke edges (relatief grote veranderingen van intensiteit) te dedecteren om definerende eigenschappen van gezichten te dedecteren.  De gezichtens uit de sample set moeten minmaal herkend worden. Daarna is snelheid de belangrijkste factor.

## 1.3. Methoden

Edge detection methode zijn op te delen in twee groepen. Eerste order operators en tweede order operators. De eerste order operators zijn gevoeliger voor ruis in de foto. 

### 1.3.1. Sobel
Sobel is een 3x3 kernel voor edge detection. Het is zelfs de meest gebruikte. Sobel is redelijk snel aangezien hij uit te drukken is in een enkele kernel.

### 1.3.2. Canny
De canny edge detection bestaat uit meerdere stappen. Allereerst word de afbeelding gesmoothed met een gausian filter. Hierna worden de afgeleides berekend in een 2x2 vierkant. Tot slot worden punten die ver uitweiken weg gefilterd. Het voordeel van dit filter is dat het werkt onder meer ruist dan sobel maar nog steeds sneller dan een second order filter.

### 1.3.3. Deriche

Deriche is een stuk ingewikkelder dan canny en bevat een schaal. Hierdoor kan er worden ingesteld hoe grof de edges gedecteerd worden. Het nadeel van dit filter is dat het nog vereist van de processor. Dit maakt het niet geschikt voor sitaties waar edge detection zo snel mogelijk moet gebeuren

### 1.3.4. Differential

Differential edge detection is een tweede order operatie. Deze operator vindt de verschillen in het gradient van de afbeelding. De edges worden gevonden door in dit gradient zero crossing punten te vinden. Op die plekken liggen de edges. De methode maakt gebruik van een 3x3 kernel. De afbeelding moet door een gaussian filter gehaald worden zodat de afbeelding juist gepresenteerd wordt voor de kernel.


### 1.3.5. Prewitt

De prewitt edge dection methode is een tweede order operatie en berekend op elk punt in de afbeelding het gradient van de intensiteit. De prewitt methode is gevoelig voor ruis in de afbeelding. Om de gevoeligheid voor ruis wat af te nemen wordt er vaak smoothing of een gaussian filter toegepast. Hierdoor neemt de ruis af en kan het resultaat van de prewitt methode betrouwbaarder zijn.
De operatie maakt gebruik van twee 3x3 kernels, één in de x richting en één in de y richting. Dit maakt het een redelijke snelle operator om uit te voeren. De snelehid gaat echter wel naar beneden als het eindresultaat beter moet zijn door het toevoegen van preprocessing stappen om de ruis weg te halen.

### 1.3.6. Roberts cross

Berekend edges aan de hand van het gradient. De operatie bestaat uit twee delen. Eerst wordt de afbeelding door een convolve filter gehaald. Vervolgens wordt er per pixel een berekening uitgevoerd. Deze twee stappen zijn vrij eenvoedig en snel uit te voeren. Echter deze methode is ook erg gevoelig voor ruis. Wederom zoals bij de Prewitt methode kan smoothing worden toegepast echter zal de effiecenty hierdoor afnemen.

## 1.4. Keuze
Je geeft een onderbouwing over waarom een bepaalde methode is gekozen, en/of waarom bepaalde settings zijn gebruikt.

## 1.5. Implementatie
Hier nog wat over second order maar doen we niet

## 1.6. Keuze
Je geeft een onderbouwing over waarom een bepaalde methode is gekozen, en/of waarom bepaalde settings zijn gebruikt.

Sobel en canny doen we

- Even laten afwachten
-Keuze doen we een second order (jordan)

## 1.7. Implementatie

De filters die we implementeren bestaan uit twee delen, een filter en de edge detection. Beide delen maken gebruik van een kernel. Dit is het belangrijkste deel om te implementeren. De kernel processor moet als input een afbeelding en een kernel hebben. Als dit deel geimplementeerd is kunnen het filter en edge dection simpel geimplenteerd worden door de juiste kernel te beschrijven en uit te laten rekenen in de kernel processor. 



## 1.8. Evaluatie
De eerste eis die in het doel staat beschreven is het herkennen van de samples uit het framework. Om dit te testen word de gemaakte edge-detection filters om de beurt in het framwork gehangen en word gekeken of alle gezichten in de sample base correct worde herekend.

Als deze test voldoet aan de eis word de tweede eis getest. Hiervoor worden beide filters 10 keer uitgevoerd. De duratie van deze taken word gemeten en zo word bepaald wat de gemiddelde snleheid van het filter is. Hierna zal een vergeleiking tussen de gemaakte filters worden uitgevoerd om te bepalen welke van de twee algoritmes het snelste is.
