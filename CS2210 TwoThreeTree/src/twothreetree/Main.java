/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package twothreetree;

/**
 *
 * @author Eric Robinson
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        twothree two3 = new twothree();

        try{
        two3.Insert(1);
        two3.Insert(2);
        two3.Insert(3);
        two3.Insert(4);
        two3.Insert(5);
//        two3.Insert(6);
//        two3.Insert(7);
//        two3.Insert(8);
//        two3.Insert(9);
  

        
        } catch (DuplicateItemException e){
            System.out.println(e);
        }

//        keyItem key = new keyItem(2);
//       two3.root.setBig(key);
//       key = new keyItem(80);
//       Node n = new Node(key,null,null,null,null);
//       two3.root.setMiddle(n);
      two3.printAscending(two3.root);

//       System.out.println(two3.root.getSmall().getKeyInt());
//       System.out.println(two3.root.getBig().getKeyInt());
        System.out.println(two3.root.getRight().getSmall().getKeyInt());

        System.out.println("");
        
       // System.out.println(two3.root.getRight().getSmall().getKeyInt());
       // System.out.println(two3.root.getRight().getBig().getKeyInt());

        System.out.println("");
    }

}
