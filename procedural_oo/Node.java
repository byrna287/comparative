import java.util.Map;

// Ailbhe Byrne
// 19424402
// I acknowledge the DCU academic integrity policy.

public class Node
{
   Map<String, String> details;    // map to hold contact details - name, number, address
   Node left;                      // left child
   Node right;                     // right child

// initialise details as argument given, left as null, right as null (no children when initialised)
   public Node(Map<String, String> details) {
      this.details = details;
      left = null;
      right = null;
   }

}
