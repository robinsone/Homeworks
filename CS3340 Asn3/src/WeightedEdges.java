/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ericrobinson
 */
public class WeightedEdges implements Comparable<WeightedEdges>{
    public int _weight;
    public int _v1;
    public int _v2;

    public WeightedEdges(int _weight, int _v1, int _v2) {
        this._weight = _weight;
        this._v1 = _v1;
        this._v2 = _v2;
    }

    public WeightedEdges() {
    }

    public int getV1() {
        return _v1;
    }

    public void setV1(int _v1) {
        this._v1 = _v1;
    }

    public int getV2() {
        return _v2;
    }

    public void setV2(int _v2) {
        this._v2 = _v2;
    }

    public int getWeight() {
        return _weight;
    }

    public void setWeight(int _weight) {
        this._weight = _weight;
    }

    @Override
    public int compareTo(WeightedEdges t) {
        if(this._weight > t._weight)
        {
            return 1;
        }
        else if(this._weight < t._weight)
        {
            return -1;
        }
        else
        {
            return 0;
        }
        
    }
    
    
    
    
}
