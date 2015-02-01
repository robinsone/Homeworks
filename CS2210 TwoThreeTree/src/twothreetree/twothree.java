/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package twothreetree;

/**
 *
 * @author Eric Robinson
 */
public class twothree {

    Node root;

    public twothree() {
        root = null;
    }

    public twothree(int number) {
        keyItem key = new keyItem(number);
        Node newItem = new Node(key, null, null, null, null);
        root = newItem;
    }

    public void Insert(int Item) throws DuplicateItemException {
        keyItem key = new keyItem(Item);
        root = insertItem2(root, key);
    }

    protected Node insertItem(Node r, keyItem newItem) throws DuplicateItemException {
        Node newSubtree;

        if (r == null) {
            r = new Node(newItem, null, null, null, null);
            return r;
        } else if (r.getSmall().getKey().equals(newItem.getKey())) {
            throw new DuplicateItemException();
        } else if (!r.hasChild()) {
            if (r.getBig() != null) {
                if (r.getBig().getKey().equals(newItem.getKey())) {
                    throw new DuplicateItemException();
                }
            }

            if (r.getBig() != null && r.getSmall() != null) {
                r = split(r, newItem);
                return r;
            } else if (r.getSmall().getKey().compareTo(newItem.getKey()) > 0) {
                r.setBig(r.getSmall());
                r.setSmall(newItem);
                return r;
            } else {
                r.setBig(newItem);
                return r;
            }
        } else {//r hasChild
            if (r.getBig() != null) {
                if (r.getBig().equals(newItem)) {
                    throw new DuplicateItemException();
                } else if (r.getSmall().getKey().compareTo(newItem) < 0) {
                    newSubtree = insertItem(r.getLeft(), newItem);
                    r.setLeft(newSubtree);
                    return r;
                } else if (r.getSmall().getKey().compareTo(newItem) > 0 && r.getBig().getKey().compareTo(newItem) < 0) {
                    newSubtree = insertItem(r.getMiddle(), newItem);
                    r.setMiddle(newSubtree);
                    return r;
                } else { //if r.bug > newItem
                    newSubtree = insertItem(r.getRight(), newItem);
                    r.setRight(newSubtree);
                    return r;
                }
            } else {
                if (r.getSmall().getKey().compareTo(newItem.getKey()) < 0) {
                    newSubtree = insertItem(r.getLeft(), newItem);
                    r.setLeft(newSubtree);
                    return r;
                } else {
                    newSubtree = insertItem(r.getRight(), newItem);
                    r.setRight(newSubtree);
                    return r;
                }

            }
        }


    }  // end insertItem

    private Node split(Node n, keyItem newItem) {


        if (n == root) {

            if (root.getBig().getKey().compareTo(newItem.getKey()) > 0) {
                Node left = new Node(root.getSmall(), null, null, null, null);
                Node right = new Node(root.getBig(), null, null, null, null);
                Node parent = new Node(newItem, null, left, null, right);
                return parent;
            } else {
                Node left = new Node(root.getSmall(), null, null, null, null);
                Node right = new Node(newItem, null, null, null, null);
                Node parent = new Node(root.getBig(), null, left, null, right);
                return parent;
            }
        } else {
            Node parent = findParent(n.getSmall());
            if (parent.getSmall() != null && parent.getBig() != null) { //3 cases
                if (n.getBig().getKey().compareTo(newItem.getKey()) < 0) {
                    parent.setBig(newItem);
                    if (parent.getSmall().getKey().compareTo(newItem.getKey()) > 0) { // on the left
                        Node left = new Node(n.getSmall(), null, null, null, null);
                        Node right = new Node(n.getBig(), null, null, null, null);
                        parent.setLeft(left);
                        parent.setMiddle(right);
                        return parent;
                    } else if (parent.getSmall().getKey().compareTo(newItem.getKey()) > 0 && parent.getBig().getKey().compareTo(newItem.getKey()) < 0) {
                    } else {
                        Node left = new Node(n.getSmall(), null, null, null, null);
                        Node right = new Node(n.getBig(), null, null, null, null);
                        parent.setMiddle(left);
                        parent.setRight(right);
                        return parent;
                    }
                }


            } else {
                parent.setBig(newItem);
                if (parent.getSmall().getKey().compareTo(newItem.getKey()) > 0) { // on the left
                    Node left = new Node(n.getSmall(), null, null, null, null);
                    Node right = new Node(n.getBig(), null, null, null, null);
                    parent.setLeft(left);
                    parent.setMiddle(right);
                    return parent;
                } else {
                    Node left = new Node(n.getSmall(), null, null, null, null);
                    Node right = new Node(n.getBig(), null, null, null, null);
                    parent.setMiddle(left);
                    parent.setRight(right);
                    return parent;
                }
            }

        }
        return null;
    }

    public Node findParent(
            keyItem key) {
        Node tempRoot = root;
        while (tempRoot != null) {

            if (root.getLeft().getSmall().getKey().compareTo(key.getKey()) == 0) {
                return root;
            } else if (root.getLeft().getBig() != null) {
                if (root.getLeft().getBig().getKey().compareTo(key.getKey()) == 0) {
                    return root;
                }

            }
            if (root.getMiddle() != null) {
                if (root.getMiddle().getSmall().getKey().compareTo(key.getKey()) == 0) {
                    return root;
                }

                if (root.getMiddle().getBig() != null) {
                    if (root.getMiddle().getBig().getKey().compareTo(key.getKey()) == 0) {
                        return root;
                    }

                }
            }
            if (root.getRight() != null) {
                if (root.getRight().getSmall().getKey().compareTo(key.getKey()) == 0) {
                    return root;
                }

                if (root.getRight().getBig() != null) {
                    if (root.getRight().getBig().getKey().compareTo(key.getKey()) == 0) {
                        return root;
                    }

                }
            }

            if (root.getSmall() != null && root.getBig() != null) {
                if (root.getSmall().getKey().compareTo(key) < 0) {
                    root = root.getLeft();
                } else if (root.getSmall().getKey().compareTo(key) > 0 && root.getBig().getKey().compareTo(key) < 0) {
                    root = root.getMiddle();
                } else {
                    root = root.getRight();
                }

            } else {
                if (root.getSmall().getKey().compareTo(key.getKey()) > 0) {
                    root = root.getLeft();
                } else {
                    root = root.getRight();
                }

            }


        }

        return null;
    }

    public Node insertItem2(
            Node root, keyItem newItem) {
        Node newSubtree;
        if (root == null) {
            root = new Node(newItem, null, null, null, null);
            return root;
        }

        if (!root.hasChild()) {
            //position found..
            if (root.getSmall() != null && root.getBig() != null) {
                root = split(root, newItem);
                return root;
            } else if (root.getSmall().getKey().compareTo(newItem.getKey()) > 0) {   //if small is smaller the newItem
                keyItem small = new keyItem(root.getSmall().getKeyInt());
                root.setSmall(newItem);
                root.setBig(small);
                return root;
            } else {
                root.setBig(newItem);
                return root;
            }

        } //if the node has two data items
        else if (root.getSmall() != null && root.getBig() != null) {
            if (root.getSmall().getKey().compareTo(newItem) < 0) {
                newSubtree = insertItem2(root.getLeft(), newItem);
                root.setLeft(newSubtree);
                return root;
            } else if (root.getSmall().getKey().compareTo(newItem) > 0 && root.getBig().getKey().compareTo(newItem) < 0) {
                newSubtree = insertItem2(root.getMiddle(), newItem);
                root.setMiddle(newSubtree);
                return root;
            } else {
                newSubtree = insertItem2(root.getRight(), newItem);
                root.setRight(newSubtree);
                return root;
            }

        } else {
            if (root.getSmall().getKey().compareTo(newItem.getKey()) > 0) {
                newSubtree = insertItem2(root.getLeft(), newItem);
                root.setLeft(newSubtree);
                return root;
            } else {
                newSubtree = insertItem2(root.getRight(), newItem);
                root.setRight(newSubtree);
                return root;
            }

        }

    }

    public void Delete() {
        return;
    }

    public void Search(int Item) {
        keyItem key = new keyItem(Item);

    }

    public Node SearchRecursive(
            Node r, keyItem key) {

        return null;

    }
    static int count = 0;

    public void printAscending(Node root) {

        //if the node is a leaf
        if (root == null) {
            return;
        }

         //if the node is a leaf
        if(!root.hasChild())
        {
            System.out.println(root.getSmall().getKey());
            if(root.getBig()!=null)
            {
                System.out.println(root.getBig().getKey());
            }
        }

        //if the node has two data items
        else if(root.getBig()!=null&&root.getBig()!=null)
        {
            printAscending(root.getLeft());
            System.out.println(root.getSmall().getKey());
            printAscending(root.getMiddle());
            System.out.println(root.getBig().getKey());
            printAscending(root.getRight());
        }

        //if the node has one data item
        else
        {
            printAscending(root.getLeft());
            System.out.println(root.getSmall().getKey());
            printAscending(root.getRight());
        }

    }

    public void Printdesc() {
    }
}
