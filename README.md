## TO DOs:
 1. contenidors + ContenidorBrossa -> comprovar si `// implementacio mes efficient` es legal.
 2. constructors Contenidors.
 3. ContenidorBrossa:
    - `operator==(ContenidorBrossa *c)` => `(*this)` or `(this)`
    - `verificar_codi()`
    - diferencia entre `getType()` i `getTipusBrossa()`??
 4. Poblacio
    - `mesRendiment()` com agafem la quantitat reciclada??? (`getReciclat()` retorna un string, extreure dades del string??)
    - `operator==(Poblacio *d)` => `(*this)` or `(this)`
    - `new node*[CONTENIDORS_LEN]` potser sempre crea el primer element de la linkedlist, volen dir que sempre el primer element tindra con==NULL (possibles problemes en totes les funcions on es fagi `while(curr)` o semblant, assumint que si primer element no es `NULL`, llavors te contingut)
 5. Comprovar el funcionament de tot