# ray_tracing

## Dependances

sur ubuntu : 
```console 
sudo apt install build-essential 
sudo apt-get install libomp-dev
```
(install g++ et les librairies de base necessaires + openmp)
## Compilation

```console
@user:~/ray_tracing$ make all
```

## Creer sa scene

modifier le fichier **data.xml**
### modifier le point de vue et les parametres du moteur graphique

#### les parametre graphiques
*vous pouvez changer les valeurs des balises*

* les attributs **width** et **height** sont la resolution de l'ecran et **pixel_size** la taille d'un pixel
* la balise **distance from screen** est la distance de l'observateur à l'ecran par lequel son lancé les rayons
* la balise **pos_viewer** represente la position de l'oeil de l'observateur dans l'espace
* les balises **u** **v** **w** sont la base de l'ecran.
* la balise **angle** permet d'effectuer une rotation du nombre de radians specifié 

**il est conseillé dans un premier temps de ne pas toucher aux vecteurs de la base (n'utiliser que rotation) de meme que la distance et la taille des pixels**
#### les parametre du calulateur
* la balise **nthread** permet de changer le nombre de thread pour le rendu de l'image **attention, ne fonctionne qu'avec le moteur parallele à selectionner dans le main.cpp**
* la balise **antialliasing** permet d'augmenter ou baisser l'antialliasing
* la balise **prof_max** permet de changer la profondeur de recursion d'un rayon 

### ajouter des objets
dans la balise **l_objets**, creer/enlevez des balises objets en respectant la forme suivante :

pour une sphere :
```xml
        <Objet name= "S1" type ="Sphere">
            <centre>
                <x>26.0</x>
                <y>4.0</y>
                <z>4.0</z>
            </centre>
            <rayon>3.0</rayon>
            <Materiaux>emerald_red</Materiaux>
        </Objet>
```
pour un plan :
```xml
        <Objet name="P_devant" type = "Plan">
            <centre>
                <x>45.0</x>
                <y>0</y>
                <z>0</z>
            </centre>
            <normale>
                <u>-1.0</u>
                <v>0</v>
                <w>0</w>
            </normale>
            <Materiaux>moquette_jaune</Materiaux>
        </Objet>
```

pour un triangle :
```xml
        <Objet name="t1" type= "Triangle">
            <B>
                <x>26.0</x>
                <y>4.0</y>
                <z>4.0</z>
            </B>
            <A>
                <x>35.0</x>
                <y>-2.0</y>
                <z>0</z>
            </A>
            <C>
                <x>35.0</x>
                <y>4.0</y>
                <z>-4.0</z>
            </C>
            <Materiaux>bronze</Materiaux>

        </Objet>
```
pour un objet complexe formé de triangle

```xml
    <Objet name = "pyramide" type="ComplexShape">
            <l_triangles>
                <Objet name="" type= "Triangle">
                    <A>
                        <x>20</x>
                        <y>-5.0</y>
                        <z>3</z>
                    </A>
                    <B>
                        <x>20</x>
                        <y>-5.0</y>
                        <z>6</z>
                    </B>
                    <C>
                        <x>17</x>
                        <y>-5.0</y>
                        <z>3</z>
                    </C>
                    <Materiaux>emerald_green</Materiaux>
        
                </Objet>
            </l_triangles>
              
              <!-- as many triangle as you want -->
              
    </Objet>
```

### ajouter des lumieres

dans la balise **l_light**, creer/enlevez des balises objets en respectant la forme suivante :


Pour une lumiere spherique :
```xml
        <light name = "L1" type="buble">
            <position>
                <x>30</x>
                <y>7.0</y>
                <z>0</z>
            </position>
            <rayon>1.0</rayon>
            <color>
                <r>0.7</r>
                <g>0.7</g>
                <b>0.7</b>
            </color>
            
        </light>
```

## Execution

lancer le main créé à la racine 
