/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Eric Robinson
 */

import java.lang.*;

/***********************************************************************
 * Class BTNode
 * The BTNode is nothing else than a Node in the BTree. This nodes can be
 * greater or smaller it depends on the users order.
 **/

class BTNode {
	int order=0;
	int nKey=0;			// number of keys stored in node
	KeyNode kArray[];		// array where keys are stored
	BTNode btnArray[];	// array where references to the next BTNodes is stored
	boolean isLeaf;		// is the btnode a leaf
	BTNode parent;		// link to the parent node

	/**
	   * BTNode(int order, BTNode parent);
	   * Constructor, creats a empty node with the given order and parent
	   **/
	BTNode(int order, BTNode parent) {
		this.order = order;
		this.parent = parent;
		kArray = new KeyNode[2 * order - 1];
		btnArray = new BTNode[2 * order];
		isLeaf = true;
	}
	/**
	   *extractKeyNode(int keyPos)
	   *Moves the key's at and behind the startpos one position right
	   **/
	KeyNode extractKeyNode(int keyIndex) {
		KeyNode tmpKeyNode = getKeyNode(keyIndex);
		for (int i = keyIndex; i < nKey; i++) {
			kArray[i] = kArray[i + 1];
			if (!isLeaf) {
				btnArray[i] = btnArray[i + 1];
			}
		}
		nKey--;
		return tmpKeyNode;
	}
	/**
	 * getBTNode(int keyIndex)
	 * returns the link to the next node at the given index from this node
	 */
	BTNode getBTNode(int keyIndex) {
		return btnArray[keyIndex];
	}
	/**
	 * getKeyNode(int keyIndex)
	 * returns the key and object from this node at the given index
	 */
	KeyNode getKeyNode(int keyIndex) {
		return kArray[keyIndex];
	}
	/**
	   *insert(KeyNode keyNode);
	   *Insert a key in a Node in the right position. (Small to Big)
	   **/
	void insert(KeyNode keyNode) {
		if (nKey == 0) {
			nKey++;
			kArray[0] = keyNode;
		} else {
			int pos = 0;
			while (keyNode.getKey().compareTo(kArray[pos].getKey()) > 0) {
				pos++;
				if (pos == nKey) {
					break;
				}
			}
			if (nKey == order * 2 - 1) {
				BTNode right = split();
				if (pos > order - 1) {
					right.insert(keyNode);
				} else {
					if (pos != nKey) {
						shift(pos);
					} else {
						nKey++;
					}
					kArray[pos] = keyNode;
				}
			} else {
				if (pos != nKey) {
					shift(pos);
				} else {
					nKey++;
				}
				kArray[pos] = keyNode;
			}
		}
	}
	// you may only applie methode to leafs...
	void mergeWithBTNode() {

		BTNode parentBTNode = parent;
		BTNode mergeBTNode;
		int parentIndex = 0;

		while (parentBTNode.getBTNode(parentIndex) != this) {
			parentIndex++;
		}

		if (parentIndex > 1) {
			mergeBTNode = parent.getBTNode(parentIndex - 1);
		} else {
			mergeBTNode = parent.getBTNode(parentIndex + 1);
		}

		if (mergeBTNode != null) {

			//geting node obove
			kArray[nKey - 1] = parentBTNode.getKeyNode(parentIndex);

			//merging leafs
			// neues probelem wenn in allen nodes nur noch ein KeyNode
			// vorhanden ist und man einen lschen mchte bleibt mergeBTNode=null
			// System.out.println(nKey + " | " + mergeBTNode);
			for (int i = nKey, j = 0; j < mergeBTNode.nKey; i++, j++) {
				kArray[i] = mergeBTNode.getKeyNode(j);
				nKey++;
			}

			int i;
			for (i = parentIndex; i < nKey; i++) {
				parentBTNode.kArray[i] = parentBTNode.kArray[i + 1];
				parentBTNode.btnArray[i + 1] = parentBTNode.btnArray[i + 2];
			}

			parentBTNode.kArray[i] = null;
			parentBTNode.btnArray[i + 1] = null;
			parentBTNode.nKey--;
		}
	}
	/**
	   *shift(int startPos)
	   *Moves the key's at, and behind the startpos one position right
	   **/
	void shift(int startPos) {
		for (int i = nKey; i > startPos; i--) {
			kArray[i] = kArray[i - 1];
			if (!isLeaf)
				btnArray[i + 1] = btnArray[i];
		}
		nKey++;
	}
	/**
	   *split()
	   *Splits a node into to nodes. This can only be done, if the node is full
	   *The midlest key go up into the parent, the left ones of them rest in
	   *this node, and the right ones go into a new node.
	   **/
	BTNode split() {
		if (nKey == order * 2 - 1) {
			BTNode right = null;
			if (parent == null) { // algo for the root-node
				BTNode left = new BTNode(order, this);
				right = new BTNode(order, this);
				for (int i = 0; i < order - 1; i++) {
					left.kArray[i] = kArray[i];
					right.kArray[i] = kArray[order + i];
				}
				if (!isLeaf) {
					for (int i = 0; i < order; i++) {
						left.btnArray[i] = btnArray[i];
						left.btnArray[i].parent = left;
						right.btnArray[i] = btnArray[order + i];
						right.btnArray[i].parent = right;
					}
					left.isLeaf = false;
					right.isLeaf = false;
				} else
					isLeaf = false;
				kArray[0] = kArray[order - 1];
				nKey = 1;
				left.nKey = order - 1;
				right.nKey = order - 1;
				for (int i = 1; i < order * 2 - 1; i++) {
					kArray[i] = null;
					btnArray[i + 1] = null;
				}
				btnArray[0] = left;
				btnArray[1] = right;
			} else { // algo for non-root-nodes
				if (parent.nKey == order * 2 - 1)
					parent.split();
				int pos = 0;
				while (kArray[order - 1].getKey().compareTo(parent.kArray[pos].getKey()) > 0) {
					pos++;
					if (pos == parent.nKey)
						break;
				}
				parent.shift(pos);
				parent.kArray[pos] = kArray[order - 1];
				right = new BTNode(order, parent);
				for (int i = 0; i < order - 1; i++)
					right.kArray[i] = kArray[order + i];
				if (!isLeaf) {
					for (int i = 0; i < order; i++) {
						right.btnArray[i] = btnArray[order + i];
						right.btnArray[i].parent = right;
					}
					right.isLeaf = false;
				}
				right.nKey = order - 1;
				nKey = order - 1;
				for (int u = 0; u < order - 1; u++) {
					kArray[order - 1 + u] = null;
					btnArray[order + u] = null;
				}
				parent.btnArray[pos] = this;
				parent.btnArray[pos + 1] = right;
			}
			return right;
		} else
			return null;
	}
}

