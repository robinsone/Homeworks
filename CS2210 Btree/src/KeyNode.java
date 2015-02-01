


/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Eric Robinson
 */
public class KeyNode {
  private Comparable searchKey;

   public KeyNode() {
    }

   public KeyNode(int key) {
      searchKey = key;
   }  // end constructor


   public Comparable getKey() {
      return searchKey;
   } // end getKey

    public int getKeyInt() {
        return Integer.parseInt(searchKey.toString());
    }
}
