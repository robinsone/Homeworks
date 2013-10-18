/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package asn2_3340;

/**
 *
 * @author ericrobinson
 */
public class Node {
    private Pixel _p;
    private Node _parent;

    public Node(Pixel p, Node parent) {
        this._p = p;
        this._parent = parent;
    }

    public Node(Pixel p) {
        this._p = new Pixel();
        this._parent = this;
    }

    public Node() {
    }

    public Pixel getPixel() {
        return _p;
    }

    public void setPixel(Pixel _p) {
        this._p = _p;
    }

    public Node getParent() {
        return _parent;
    }

    public void setParent(Node _parent) {
        this._parent = _parent;
    }
    
    
   
}
