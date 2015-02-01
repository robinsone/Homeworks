/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package twothreetree;

/**
 *
 * @author Eric Robinson
 */
public class keyItem {
    private Comparable searchKey;

   public keyItem() {
    }

   public keyItem(int key) {
      searchKey = key;
   }  // end constructor


   public Comparable getKey() {
      return searchKey;
   } // end getKey

    public int getKeyInt() {
        return Integer.parseInt(searchKey.toString());
    }


}
