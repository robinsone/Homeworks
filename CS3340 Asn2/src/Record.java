/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ericrobinson
 */
class Record implements Comparable {

    private char _word;
    private int _freq;

    public Record(char _word, int _freq) {
        this._word = _word;
        this._freq = _freq;
    }

    public int getFreq() {
        return _freq;
    }

    public void setFreq(int _freq) {
        this._freq = _freq;
    }

    public char getWord() {
        return _word;
    }

    public void setWord(char _word) {
        this._word = _word;
    }

    
    
    

    @Override
    public int compareTo(Object t) throws ClassCastException {
        if (!(t instanceof Record)) {
            //throw new ClassCastException("A Record object expected.");
            return 0;
        }
        int tfreq = ((Record) t).getFreq();
        return tfreq - this.getFreq();
    }
}
