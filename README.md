# ADTs
programming II lab practicals 
organized each practical on each p folder, it has 3 different folders, each implementing some ADT

### p0 - abstract implementation of rational numbers
given code defines rational numbers by hand, basics of headers and having several files

BIDFIC: online auction website -> must store all information asocciated with the products
### p1 - bidfic (static and singly linked dynamic list)
this practical consists of implementing the main features of an online auction site, a data structure capable of storing all the information of products is to be implemented
there will be two different implementations:
- one using an static list
- one using a dynamic list
the main program should read a txt file following a given format and work regardless of the implementation selected, implementing the following functionality:
- new: a product should be added at the end of the product list
- delete: a product will be removed from the list
- bid: add a bid to a product
- stats: print information on the current state of the list


### p2 - bidfic (stack and singly linked dynamic list)
the problem is the same that in the p1, but now an stack is implemented to store the bids, and is a parameter of each product
there will be just one implementation on the main, but still should not rely on the specifics of the implementation
moreover, the main will have added functionality:
- award: the best bidder for a product is declared
- withdraw: xurrnt highest bid for a product is withdrawn
- remove: delete all products with no bids
