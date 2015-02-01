import java.lang.*;
import java.util.Enumeration;

import org.javaldap.server.syntax.*;

/**
* Main Class BTree
* For creating a fully BTree with all Methods and Attributs
**/
public class BTree {
	int order;
	BTNode root;

	/**
	 * Constructor
	 * creates the root of a btree
	 */
	public BTree(int order) {
		this.order=order;
		root=new BTNode(order, null);
	}
	public boolean containsKey(String key) {
		if (get(key) != null) return true;
		return false;
	}
	public boolean containsKey(DirectoryString ds) {
		if (get(ds) != null) return true;
		return false;
	}
	/*
	   * main delet methode
	   * for recursiv coding
	   */
	KeyNode deleteNode(BTNode btnode, Comparator key) {
		// get information needed
		SearchResult tmpResult = searchObj(btnode, key);
		BTNode delBTNode = tmpResult.getBTNode();
		if (delBTNode == null) {
			return null;
		}
		int keyIndex = tmpResult.getKeyIndex();
		KeyNode returnNode = delBTNode.getKeyNode(keyIndex);

		// is a leaf **********************************
		if (delBTNode.isLeaf) {
			if (delBTNode.nKey > order - 1)
				// we can delete KeyNode directly
			{
				delBTNode.extractKeyNode(keyIndex);
			} else
				// we need to get more keys so that we can delete it
			{
				BTNode parentBTNode = delBTNode.parent;
				int parentIndex = 0;
				while (parentBTNode.getBTNode(parentIndex) != delBTNode)
					parentIndex++;
				if (parentIndex == parentBTNode.nKey) {
					BTNode leftBTNode = parentBTNode.getBTNode(parentIndex - 1);
					if (leftBTNode.nKey > order - 1) {
						delBTNode.kArray[keyIndex] = parentBTNode.getKeyNode(parentIndex);
						parentBTNode.kArray[parentIndex] = leftBTNode.getKeyNode(leftBTNode.nKey - 1);
						deleteNode(leftBTNode, leftBTNode.getKeyNode(leftBTNode.nKey - 1).getKey());
					} else {
						delBTNode.mergeWithBTNode();
					}
				} else {
					BTNode rightBTNode = parentBTNode.getBTNode(parentIndex + 1);
					if (rightBTNode.nKey > order - 1) {
						delBTNode.kArray[keyIndex] = parentBTNode.getKeyNode(parentIndex);
						parentBTNode.kArray[parentIndex] = rightBTNode.getKeyNode(0);
						deleteNode(rightBTNode, rightBTNode.getKeyNode(0).getKey());
					} else {
						delBTNode.mergeWithBTNode();
					}
				}
			}
		} else
			// is internal node *********************
		{
			//try predecesor
			// get the node to exchange and delete it at leaf position
			BTNode preBTNode = delBTNode.getBTNode(keyIndex);
			while (!preBTNode.isLeaf) {
				preBTNode = preBTNode.getBTNode(preBTNode.nKey);
			}

			// swap nodes
			KeyNode tmpKeyNode = preBTNode.getKeyNode(preBTNode.nKey - 1);
			preBTNode.kArray[preBTNode.nKey - 1] = delBTNode.kArray[keyIndex];
			delBTNode.kArray[keyIndex] = tmpKeyNode;
			deleteNode(preBTNode, preBTNode.getKeyNode(preBTNode.nKey - 1).getKey());
		}
		return returnNode;
	}
	/**
	 * deletes the object stored with the given key
	 **/
	public KeyNode deleteObj(Comparator key) {
		return deleteNode(root, key);
	}
	public Object get(Long key) {
		return getKeyObject(new LongComparator(key));
	}
	public Object get(String key) {
		return getKeyObject(new StringComparator(key));
	}
	public Object get(DirectoryString key) {
		return getKeyObject(new DirectoryStringComparator(key));
	}
	/**
	 * returns the object stored behind the given key
	 */
	public Object getKeyObject(Comparator key) {
		SearchResult result=searchObj(root, key);
		if(result.getBTNode()==null)
			return null;
		else
			return (result.getBTNode().getKeyNode(result.getKeyIndex())).getObj();
	}
	/**
	 * insert a object with the given key into the tree
	 */
	public void insertObj(Comparator key, Object data) {
		KeyNode keyNode = new KeyNode(key, data);
		BTNode btNode = root;
		while (!btNode.isLeaf) {
			int i=0;
			while(keyNode.getKey().compareTo(btNode.kArray[i].getKey()) > 0) {
				i++;
				if (i == btNode.nKey) break;
			}
			btNode = btNode.btnArray[i];
		}
		btNode.insert(keyNode);
		if (root.nKey == order*2-1) root.split();
	}
	public Enumeration keys() {
		return new BTreeEnumeration(this,true);
	}
	public void put(Long key, Object val) {
		insertObj(new LongComparator(key),val);
	}
	public void put(String key, Object val) {
		insertObj(new StringComparator(key),val);
	}
	public void put(DirectoryString key, Object val) {
		insertObj(new DirectoryStringComparator(key),val);
	}
	public void remove(String key) {
		deleteObj(new StringComparator(key));
	}
	public void remove(DirectoryString key) {
		deleteObj(new DirectoryStringComparator(key));
	}
	/*
	 * returns null in the btnode part and -1 in the keyIndex
	 * if the specified key doesn't exist
	 */
	SearchResult searchObj(BTNode btnode, Comparator key) {
		SearchResult resultObj=new SearchResult(null, -1);
		int i=0;
		boolean keyNotInNode=false;
		boolean keyFound=false;

		while(!keyNotInNode && !keyFound) {

			if(btnode.getKeyNode(i) != null && key.compareTo(btnode.getKeyNode(i).getKey())<0) {
				keyNotInNode=true;
				if(!btnode.isLeaf)
					resultObj=searchObj(btnode.getBTNode(i), key);
			} else
				if(btnode.getKeyNode(i) != null && key.compareTo(btnode.getKeyNode(i).getKey())==0) {
					keyFound=true;
					resultObj=new SearchResult(btnode, i);//key found
				}
				else if(i<(btnode.nKey-1))i++;
				else
					if(btnode.getKeyNode(i) != null && key.compareTo(btnode.getKeyNode(i).getKey())>0) {
						keyNotInNode=true;
						if(!btnode.isLeaf)
							resultObj=searchObj(btnode.getBTNode(i+1), key);
					} else keyNotInNode=true;

		}
		return resultObj;
	}
	public Enumeration values() {
		return new BTreeEnumeration(this,false);
	}
}