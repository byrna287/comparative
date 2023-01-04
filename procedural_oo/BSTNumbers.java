import java.util.Map;

// Ailbhe Byrne
// 19424402
// I acknowledge the DCU academic integrity policy.

public class BSTNumbers
{
   Node root;

// initialise root as null (empty tree)
   public BSTNumbers() {
      this.root = null;
   }

// method to store contact in bst, sorted by number
   public void store_number(Map<String, String> details) {
      root = rec_store_number(root, details);
   }

   public Node rec_store_number(Node ptr, Map<String, String> details) {
      if (ptr == null) {
         return new Node(details);    // store node in right place found
      }
      else if (details.get("number").compareTo(ptr.details.get("number")) < 0) {   // if number to be stored is smaller (alphabetically) than current number, go down left side of tree
         ptr.left = rec_store_number(ptr.left, details);
      }
      else if (details.get("number").compareTo(ptr.details.get("number")) > 0) {   // if number to be stored is bigger (alphabetically) than current number, go down right side of tree
         ptr.right = rec_store_number(ptr.right, details);
      }
      return ptr;
   }

// method to search bst for contact, using the number
   public Map<String, String> search_number(String number) {
      return rec_search_number(root, number);
   }

   public Map<String, String> rec_search_number(Node ptr, String number) {
      if (ptr == null) {
         return null;     // if contact not in tree
      }
      else if (number.equals(ptr.details.get("number"))) {   // if number is found
         return ptr.details;
      }
      else if (number.compareTo(ptr.details.get("number")) < 0) {   // if number to be found is smaller (alphabetically) than current number
         return rec_search_number(ptr.left, number);                // go down left side of tree
      }
      else {
         return rec_search_number(ptr.right, number);   // otherwise go down right side of tree
      }
   }

// method to remove a contact from bst, using the number
   public void remove_number(String number) {
      root = rec_remove_number(root, number);
   }

   public Node rec_remove_number(Node ptr, String number) {
      if (ptr == null) {
         return null;     // if contact not in tree
      }
      else if (ptr.details.get("number").equals(number)) {   // if contact is found
         if (ptr.left == null && ptr.right == null) {        // if node has no children
            return null;
         }
         else if (ptr.left != null && ptr.right == null) {    // if node only has left child
            return ptr.left;
         }
         else if (ptr.left == null && ptr.right != null) {    // if node only has right child
            return ptr.right;
         }
         else {                                                                   // if node has 2 children
            Map<String, String> new_details = firstStrAlpha(ptr.right);           // find smallest number in right child
            ptr.details = new_details;                                            // overwrite node to be deleted
            ptr.right = rec_remove_number(ptr.right, new_details.get("number"));  // delete node which has been moved's old node
            return ptr;
         }
      }
      else if (number.compareTo(ptr.details.get("number")) < 0) {   // if number is smaller (alphabetically) than current number, go down left side of tree
         ptr.left = rec_remove_number(ptr.left, number);
         return ptr;
      }
      else {
         ptr.right = rec_remove_number(ptr.right, number);   // otherwise go down right side of tree
         return ptr;
      }
   }

// method to find contact in tree with smallest number (alphabetically) 
   public Map<String, String> firstStrAlpha(Node ptr) {
      if (ptr.left == null) {
         return ptr.details;
      }
      else {
         return firstStrAlpha(ptr.left);
      }
   }

}
