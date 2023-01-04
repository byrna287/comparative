import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

// Ailbhe Byrne
// 19424402
// I acknowledge the DCU academic integrity policy.

public class Loop
{
   public static void main(String [] args) {

      BSTNames phonebookNames = new BSTNames();         // bst object which sorts on name
      BSTNumbers phonebookNumbers = new BSTNumbers();   // bst object which sorts on number
      Scanner in = new Scanner(System.in);              // scanner object to read from stdin
      System.out.println("Welcome to the phonebook!");
      System.out.println("To ADD a contact, enter A");
      System.out.println("To FIND a contact, enter F");
      System.out.println("To DELETE a contact, enter D");
      System.out.println("To QUIT the phonebook, enter Q");

      while (true) {

         System.out.print("$ ");
         Map<String, String> details = new HashMap<>();   // map to hold contact details - name, number, address
         String command = in.nextLine();                  // read in command for phonebook
         if (command.equals("Q")) {                       // if command is quit
            System.out.println("Goodbye!");
            break;                                 // exit while loop
         }
         else if (command.equals("A")) {           // if command is add
            System.out.print("Enter name: ");
            String name = in.nextLine();           // read in name
            details.put("name", name);             // add name to map

            System.out.print("Enter number: ");
            String number = in.nextLine();         // read in number
            details.put("number", number);         // add number to map

            System.out.print("Enter address: ");
            String address = in.nextLine();        // read in address
            details.put("address", address);       // add address to map

            if (phonebookNames.search_name(name) == null && phonebookNumbers.search_number(number) == null) {      // if name and number not in phonebook
               phonebookNames.store_name(details);               // add contact to bst for names
               phonebookNumbers.store_number(details);           // add contact to bst for numbers
               System.out.println("Contact has been added!");
            }
            else {
               System.out.println("Name or number are already in the phonebook!");
            }
         }
         else if (command.equals("F")) {       // if command is find
            System.out.println("To FIND a contact by NAME, enter 1");
            System.out.println("To FIND a contact by NUMBER, enter 2");
            String option = in.nextLine();     // read in option for find

            if (option.equals("1")) {             // if option is find by name
               System.out.print("Enter name: ");
               String name = in.nextLine();       // read in name
               Map<String, String> contact = phonebookNames.search_name(name);    // get contact from bst for names
               if (contact != null) {                                             // if contact is in phonebook
                  System.out.println("Name: " + contact.get("name"));
                  System.out.println("Number: " + contact.get("number"));
                  System.out.println("Address: " + contact.get("address"));
               }
               else {
                  System.out.println("They are not in the phonebook!");
               }
            }
            else if (option.equals("2")) {        // if option is find by number
               System.out.print("Enter number: ");
               String number = in.nextLine();     // read in number
               Map<String, String> contact = phonebookNumbers.search_number(number);    // get contact from bst for numbers
               if (contact != null) {                                                   // if contact is in phonebook
                  System.out.println("Name: " + contact.get("name"));
                  System.out.println("Number: " + contact.get("number"));
                  System.out.println("Address: " + contact.get("address"));
               }
               else {
                  System.out.println("They are not in the phonebook!");
               }
            }
            else {
               System.out.println("Re-enter a valid command!");    // if doesn't enter 1 or 2, error message and look for new command
            }
         }
         else if (command.equals("D")) {       // if command is delete
            System.out.print("Enter name: ");
            String name = in.nextLine();       // read in name
            Map<String, String> contact = phonebookNames.search_name(name);   // get contact from bst for names
            if (contact != null) {                                            // if contact is in phonebook
               phonebookNames.remove_name(name);                              // delete from bst for names
               phonebookNumbers.remove_number(contact.get("number"));         // delete from bst for numbers
               System.out.println("Contact has been deleted!");
            }
            else {
               System.out.println("They are not in the phonebook!");
            }
         }
         else {
            System.out.println("Re-enter a valid command!");    // if doesn't enter A, F, D, or Q, error message and look for new command
         }
      }
      in.close();   // close scanner
   }
}
