# Workshop C++  <br> Mathias RAKOTOMAVO


[Lien github](https://github.com/Mathyazerty/mathias_workshop)


## 1. Ne garder que le vert

![Logo vert](imagesexport/ex1_logo_vert.png)

## 2. Échanger les canaux

![Logo échanger les canaux](imagesexport/ex2_echange_canaux.png)

## 3. Noir & Blanc

![Logo noir & blanc](imagesexport/ex3_n&b.png)

## 4. Négatif

![Logo négatif](imagesexport/ex4_negatif.png)

## 5. Degrade
![Logo dégradé](imagesexport/ex5_degrade.png)

## 6.Mirroir
![Logo mirroir](imagesexport/ex6_miroir.png)

J’ai eu plus de difficulté avec les mouvements de pixels qu’avec les changements de couleur. Pour modifier une couleur, il suffit de changer les valeurs du pixel à sa place. Pour déplacer un pixel, il faut comprendre où il se trouve au départ, calculer sa nouvelle position et éviter d’écraser d’autres pixels. C’était donc moins intuitif pour moi.

## 7.Image bruitée
![Logo bruité](imagesexport/ex7_bruite.png)

## 8. Rotation de 90°
![Logo rotation](imagesexport/ex8_rotation.png)

Au début, j’ai eu du mal à comprendre la formule de rotation, surtout pourquoi on inverse la coordonnée avec image.height() - 1 - y. J’ai fini par comprendre qu’elle permet de parcourir les positions dans le sens opposé.

## 9.RGB split
![Logo RGB split](imagesexport/ex9rgbsplit.png)

## 10 Luminosité
![Logo luminosité](imagesexport/ex10lumi_clair.png)
![Logo luminosité](imagesexport/ex10lumi_foncee.png)

## 11. Disque
![Logo disque](imagesexport/ex11_disque.png)
je ne comprenais pas comment on pouvait savoir si un pixel se trouvait à l’intérieur ou à l’extérieur du disque. Il fallait calculer sa distance au centre et la comparer au rayon.

## 12. Cercle
![Logo cercle](imagesexport/ex12_cercle.png)

## 13. Animation
![Logo animation](imagesexport/ex13_gif_animation.gif)

## 14. Rosace
![Logo rosace fail](imagesexport/ex14_rosacefail.png)

J'ai rencontré quelques difficultés, notamment pour gérer le positionnement des cercles sur le coutour du cercle pile au centre.

Et voici quel a été mon premier resultat, le problème ici à été que les cercles avaient tous un cercle noir à l'intérieur d'eux, ce qui créait le contour blanc. Cependant je n'ai pas pu utiliser cette technique ici car les cercles se chevauchent, j'ai donc du calculer et colorer uniquement les pixels situés entre le rayon et la thickness.
![Logo rosace](imagesexport/ex14_rosace.png)

## 15. Mosaïque
![Logo mosaïque](imagesexport/ex14_mosaique.png)

## 16. Mosaïque miroir
![Logo mosaïque miroir](imagesexport/ex15_mosaiquemirr.png)
J’ai eu du mal à comprendre qu’on pouvait inverser les pixels d’une copie sans déplacer la copie elle-même : seule la position du pixel lu dans l’image d’origine change, tandis que sa position dans la mosaïque reste la même.

### 17. Glitch
![Logo glitch fail](imagesexport/ex16_glitchfail.png)

Pour tester j'ai décidé de remplacer des rectangles de couleurs aléatoires plutot que des pixels aléatoires.

Voici le resusltat, le programme utilisait sa couleur pour peindre un petit rectangle. Cela arrivait environ 300 fois. Les rectangles se recouvraient et repeignaient parfois des zones déjà modifiées, ce qui étalait la couleur des pixels en rectangles, plutôt que de déplacer des morceaux de l’image.

![Logo glitch](imagesexport/ex16_glitch.png)