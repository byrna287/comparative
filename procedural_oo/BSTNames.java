import java.util.Map;

// Ailbhe Byrne
// 19424402
// I acknowledge the DCU academic integrity policy.

public class BSTNames
{
   Node root;

// initialise root as null (empty tree)
   public BSTNames() {
      this.root = null;
   }

// method to store contact in bst, sorted by name
   public void store_name(Map<String, String> details) {
      root = rec_store_name(root, details);
   }

   public Node rec_store_name(Node ptr, Map<String, String> details) {
      if (ptr == null) {
         return new Node(details);   // store node in right place found
      }
      else if (details.get("name").compareTo(ptr.details.get("name")) < 0) {   // if name to be stored is alphabetically before current name, go down left side of tree
         ptr.left = rec_store_name(ptr.left, details);
      }
      else if (details.get("name").compareTo(ptr.details.get("name")) > 0) {   // if name to be stored is alphabetically after current name, go down right side of tree
         ptr.right = rec_store_name(ptr.right, details);
      }
      return ptr;
   }

// method to search bst for contact, using the name
   public Map<String, String> search_name(String name) {
      return rec_search_name(root, name);
   }

   public Map<String, String> rec_search_name(Node ptr, String name) {
      if (ptr == null) {
         return null;     // if contact not in tree
      }
      else if (name.equals(ptr.details.get("name"))) {   // if name is found
         return ptr.details;
      }
      else if (name.compareTo(ptr.details.get("name")) < 0) {   // if name to be found is alphabetically before current name, go down left side of tree
         return rec_search_name(ptr.left, name);
      }
      else {
         return rec_search_name(ptr.right, name);   // otherwise go down right side of tree
      }
   }

// method to remove a contact from bst, using the name
   public void remove_name(String name) {
      root = rec_remove_name(root, name);
   }

   public Node rec_remove_name(Node ptr, String name) {
      if (ptr == null) {
         return null;     // if contact not in tree
      }
      else if (ptr.details.get("name").equals(name)) {    // if contact is found
         if (ptr.left == null && ptr.right == null) {     // if node has no children
            return null;
         }
         else if (ptr.left != null && ptr.right == null) {    // if node only has left child
            return ptr.left;
         }
         else if (ptr.left == null && ptr.right != null) {    // if node only has right child
            return ptr.right;
         }
         else {                                                                // if node has 2 children
            Map<String, String> new_details = firstStrAlpha(ptr.right);        // find first string alphabetically in right child
            ptr.details = new_details;                                         // overwrite node to be deleted
            ptr.right = rec_remove_name(ptr.right, new_details.get("name"));   // delete node which has been moved's old node
            return ptr;
         }
      }
      else if (name.compareTo(ptr.details.get("name")) < 0) {   // if name is alphabetically before current name, go down left side of tree
         ptr.left = rec_remove_name(ptr.left, name);
         return ptr;
      }
      else {
         ptr.right = rec_remove_name(ptr.right, name);   // otherwise go down right side of tree
         return ptr;
      }
   }

// method to find contact in tree with first string alphabetically
   public Map<String, String> firstStrAlpha(Node ptr) {
      if (ptr.left == null) {
         return ptr.details;
      }
      else {
         return firstStrAlpha(ptr.left);
      }
   }

}
