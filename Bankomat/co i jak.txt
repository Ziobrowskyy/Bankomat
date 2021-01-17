/*

osobnik podchodzi do bankomatu w calu innym ni¿ kradzie¿

wykonuj¹c wyp³ate wybiera j¹ na ekranie,
	
	jako operacje kart¹ podaje kartê i pin do niej 
	z karty zczytywany jest nr karty i wysy³any do sieci
	z sieci pobierane s¹ informacje: pin, stan œrodków, limity, nr konta 
	po zweryfikowaniu karty kodem pin klient wybiera kwotê podzieln¹ przez 10
	zadana kwota jest porównywana ze stanem konta a nastepnie z limitem 
	jêsli bankomat nie posiada wystarczaj¹co œrodków transakcja jest anulowana
	jeœli nie ma wystarczajacych œrodków wrcamy do wyboru kwoty lub anulujemy ca³¹ transakcjie
	jeœli limit nie pozwala wyp³acic œrodków wrcamy do wyboru kwoty lub anulujemy ca³¹ transakcjie

	jako operacje blik 
	pobieramy informacje o kwocie jak¹ chemy wyp³aciæ 
	pobieramy kod blik od klienta
	wysy³amy zapytanie do sieci o realizacje transakcji
	jeœli innformacja zwrotna nie pozwala na operacje zaczynamy wszytko od nowa lub anulujemy transakcje 

	
jeœli wszystko ok to wyp³acamy banknoty, drukujemy potwierdzenie, *oddajemy kartê, wysy³amy informacje do systemu o wyp³acie x œrodków z danego konta
dodatkowo bankomat mo¿e odj¹æ kwotê x od aktualnego bilansu aby na bierz¹co monitorowaæ zasób dstêpnych œrodków
usuwamy informacje o kliencie który w³aœnie wykonywa³ transakcje
*/




/*
wykonuj¹c wp³ate wybiera j¹ na ekranie,

	jako operacje kart¹ podaje kartê i pin do niej
	z karty zczytywany jest nr karty i wysy³any do sieci
	z sieci pobierane s¹ informacje: pin, stan œrodków, limity, nr konta
	po zweryfikowaniu karty kodem pin klient wybiera kwotê podzieln¹ przez 10 któr¹ chce wp³aciæ
	ponbierana jest gotówka jako pojedyñcze banknoty które zostaj¹ przeskanowane operacja trwa do uzyskania zadanej kwoty lub anulowania transakji
	po zakoñczeniu pobierania pieniêdzy wyœwietlamy komunikat o wp³aconej kwocie  
	po akceptacji przez klienta 



	jako operacje blik
	pobieramy informacje o kwocie jak¹ chemy wyp³aciæ
	pobieramy kod blik od klienta
	ponbierana jest gotówka jako pojedyñcze banknoty które zostaj¹ przeskanowane operacja trwa do uzyskania zadanej kwoty lub anulowania transakji
	po zakoñczeniu pobierania pieniêdzy wyœwietlamy komunikat o wp³aconej kwocie
	wysy³amy informacje o wp³acie kwoty x z pomoc¹ danego kodu blik do systemu

	

jeœli wszystko ok to  drukujemy potwierdzenie, *oddajemy kartê, *wysy³amy informacje do systemu o wp³acie x œrodków na dane konto
dodatkowo bankomat mo¿e dodaæ kwotê x do aktualnego bilansu aby na bierz¹co monitorowaæ zasób dstêpnych œrodków
usuwamy informacje o kliencie który w³aœnie wykonywa³ transakcje
*/

/*
wykonuj¹c sprawdzenie stanu konta wybiera j¹ na ekranie,

jako operacje kart¹ podaje kartê i pin do niej
z karty zczytywany jest nr karty i wysy³any do sieci
z sieci pobierane s¹ informacje : pin, stan œrodków, limity, nr konta
nastêpnie wyœwietlany jest stan konta 

po zakoñczeniu operacji klijent mo¿e wybraæ opcje wp³aty i wyp³aty

jeœli wybierze koniec transakcji zostaje mu zwrócona karta 
po zakoñczeniu dzia³añ informacje o kliencie zostaj¹ usuniete
*/

/*

do bankomatu podchodzi bardzo kompetentny pracownik 

na ekranie g³ównym wybiera dostêp s³u¿bowy
podaje swój nr identyfikacyjny
z systemu zostaje pobrana informacja o haœle wyreyfikuj¹cym pracownika
pracownik podaje has³o 
po weryfikacji has³a pracownik dostaje nieograniczony dostêp do wszytkich mo¿liwoœci w bankomacie

po zakoñczeniu pracy pracownik daje ssygna³ typu koniec pracy
bankomat wraca do normalnego stanu
usuwane s¹ informacje o pracwniku i haœle


*/