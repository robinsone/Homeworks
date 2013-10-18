/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package asn2_3340;

/**
 *
 * @author ericrobinson
 */
public class Pixel {
    
    private int x;//column
    private int y;//row
    private char value;//character
    
    public Pixel() {
        this.x = 0;
        this.y = 0;
        this.value = ' ';
    }
    
    public Pixel(int x, int y, char value){
        this.x = x;
        this.y = y;
        this.value = value;
    }

    public char getValue() {
        return value;
    }

    public void setValue(char value) {
        this.value = value;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
    
    
    
}
