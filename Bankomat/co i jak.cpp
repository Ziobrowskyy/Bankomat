/*

osobnik podchodzi do bankomatu w calu innym ni� kradzie�

wykonuj�c wyp�ate wybiera j� na ekranie,
	
	jako operacje kart� podaje kart� i pin do niej 
	z karty zczytywany jest nr karty i wysy�any do sieci
	z sieci pobierane s� informacje: pin, stan �rodk�w, limity, nr konta 
	po zweryfikowaniu karty kodem pin klient wybiera kwot� podzieln� przez 10
	zadana kwota jest por�wnywana ze stanem konta a nastepnie z limitem 
	j�sli bankomat nie posiada wystarczaj�co �rodk�w transakcja jest anulowana
	je�li nie ma wystarczajacych �rodk�w wrcamy do wyboru kwoty lub anulujemy ca�� transakcjie
	je�li limit nie pozwala wyp�acic �rodk�w wrcamy do wyboru kwoty lub anulujemy ca�� transakcjie

	jako operacje blik 
	pobieramy informacje o kwocie jak� chemy wyp�aci� 
	pobieramy kod blik od klienta
	wysy�amy zapytanie do sieci o realizacje transakcji
	je�li innformacja zwrotna nie pozwala na operacje zaczynamy wszytko od nowa lub anulujemy transakcje 

	
je�li wszystko ok to wyp�acamy banknoty, drukujemy potwierdzenie, *oddajemy kart�, wysy�amy informacje do systemu o wyp�acie x �rodk�w z danego konta
dodatkowo bankomat mo�e odj�� kwot� x od aktualnego bilansu aby na bierz�co monitorowa� zas�b dst�pnych �rodk�w
usuwamy informacje o kliencie kt�ry w�a�nie wykonywa� transakcje
*/




/*
wykonuj�c wp�ate wybiera j� na ekranie,

	jako operacje kart� podaje kart� i pin do niej
	z karty zczytywany jest nr karty i wysy�any do sieci
	z sieci pobierane s� informacje: pin, stan �rodk�w, limity, nr konta
	po zweryfikowaniu karty kodem pin klient wybiera kwot� podzieln� przez 10 kt�r� chce wp�aci�
	ponbierana jest got�wka jako pojedy�cze banknoty kt�re zostaj� przeskanowane operacja trwa do uzyskania zadanej kwoty lub anulowania transakji
	po zako�czeniu pobierania pieni�dzy wy�wietlamy komunikat o wp�aconej kwocie  
	po akceptacji przez klienta 



	jako operacje blik
	pobieramy informacje o kwocie jak� chemy wyp�aci�
	pobieramy kod blik od klienta
	ponbierana jest got�wka jako pojedy�cze banknoty kt�re zostaj� przeskanowane operacja trwa do uzyskania zadanej kwoty lub anulowania transakji
	po zako�czeniu pobierania pieni�dzy wy�wietlamy komunikat o wp�aconej kwocie
	wysy�amy informacje o wp�acie kwoty x z pomoc� danego kodu blik do systemu

	

je�li wszystko ok to  drukujemy potwierdzenie, *oddajemy kart�, *wysy�amy informacje do systemu o wp�acie x �rodk�w na dane konto
dodatkowo bankomat mo�e doda� kwot� x do aktualnego bilansu aby na bierz�co monitorowa� zas�b dst�pnych �rodk�w
usuwamy informacje o kliencie kt�ry w�a�nie wykonywa� transakcje
*/

/*
wykonuj�c sprawdzenie stanu konta wybiera j� na ekranie,

jako operacje kart� podaje kart� i pin do niej
z karty zczytywany jest nr karty i wysy�any do sieci
z sieci pobierane s� informacje : pin, stan �rodk�w, limity, nr konta
nast�pnie wy�wietlany jest stan konta 

po zako�czeniu operacji klijent mo�e wybra� opcje wp�aty i wyp�aty

je�li wybierze koniec transakcji zostaje mu zwr�cona karta 
po zako�czeniu dzia�a� informacje o kliencie zostaj� usuniete
*/

/*

do bankomatu podchodzi bardzo kompetentny pracownik 

na ekranie g��wnym wybiera dost�p s�u�bowy
podaje sw�j nr identyfikacyjny
z systemu zostaje pobrana informacja o ha�le wyreyfikuj�cym pracownika
pracownik podaje has�o 
po weryfikacji has�a pracownik dostaje nieograniczony dost�p do wszytkich mo�liwo�ci w bankomacie

po zako�czeniu pracy pracownik daje ssygna� typu koniec pracy
bankomat wraca do normalnego stanu
usuwane s� informacje o pracwniku i ha�le


*/