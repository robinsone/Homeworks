package binarytreedictionary;


public class TreeNode {
  private String Word;
  private int count;
  private TreeNode leftChild;
  private TreeNode rightChild;

  public TreeNode(String word, int count) {
  // Initializes tree node with item and no children.
    this.Word = word;
    this.count = count;
    leftChild  = null;
    rightChild = null;
  }  // end constructor

  public TreeNode(String word, int count,
                  TreeNode left, TreeNode right) {
  // Initializes tree node with item and
  // the left and right children references.
    this.Word = word;
    this.count = count;
    leftChild  = left;
    rightChild = right;
  }  // end constructor

    public String getWord() {
        return Word;
    }

    public void setWord(String Word) {
        this.Word = Word;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public TreeNode getLeft() {
        return leftChild;
    }

    public void setLeft(TreeNode leftChild) {
        this.leftChild = leftChild;
    }

    public TreeNode getRight() {
        return rightChild;
    }

    public void setRight(TreeNode rightChild) {
        this.rightChild = rightChild;
    }
 


    @Override
  public String toString() {
	  return Word.toString();
  }

  public boolean isLeaf() {
    return ((getLeft() == null) && (getRight() == null));
  }

}  // end TreeNode