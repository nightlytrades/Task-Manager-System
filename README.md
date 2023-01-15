# Task Manager
  
 > Authors: [Amir Shirazi](https://github.com/ashirazi77), [Javier Hernandez](https://github.com/Jav-H), [Kunal Ram](https://github.com/kunalram39)
 
## Project Description
 > #### Reason for Interest
 > * As students, we are expected to track assignments and projects individually and effectively. Consequently, we have become very familiar with using task manager applications, and we wanted to create one that appealed to our student needs by factoring in which lecture class the task is assigned to.
 > #### Language
 > * The project will be developed in C++. 
 > #### Input & Output
 > * Task Manager will request title, description, lecture class, priority, duration, and due date as possible inputs to create a task. The application will then output a list of tasks that are organized by date and either lecture or priority, which can be further edited or undone by the user. The user may also create task lists to incorporate multiple tasks into a single object. 
 > #### Design Patterns
 > * We will be using a composite design pattern, in which the primitives will be tasks and compositions will be task lists. This project calls for the simultaneous representation of simple and complex hierarchies within an interface. Normally, problems will arise when interfacing with two objects of varying complexity. But using composite design, clients can treat tasks and task lists as the same, even though they are of two separate complexities. 
 > * In addition, we will use an iterative design pattern to navigate through the hierarchies with the varying tasks. The iterator interface unfolds different navigation methods and a container interface that returns the iterator. The main function of this pattern is to access the elements which are in the aggregate object in a sequential method. In this project, the task list is an aggregate object that must be iterated through to access its primitives (tasks). Since the user cannot access the tasks and the task list in the same manner, iterative design must be implemented to properly parse through the lists. 
 

 > ## User Stories and development tasks
 > * Epics and development tasks were created and assigned to group members
 >    - Sidenote: When searching for Amirreza's username, it wouldn't populate. Several issues were left without an assignee but will be added once we figure out why Amirreza's username isn't given as an option.
 > ## Class Diagram
 > ![Task_Manager_Diagram](https://github.com/cs100/final-project-kram003-ashir025-jhern571/blob/master/images/diagram.jpeg)
 > #### Iterator Design
 > * The right half of the class diagram, which includes all of the Iterator classes, consists of the Iterator design pattern. Each Iterator subclass represents an alternate path for the client to organize the tasks: by date, priority, or class. 
 > #### Composite Design
 > * The left half, with the virtual Task and its subclasses, consists of the Composite design pattern. Both BasicTask and TaskList, which are primitives and compositions, respectively, are expressed uniformly within the hierarchy. The composition will aggregate the Task class. 
 
 ## Sprint Plan #2
 > Items currently being worked on:
 > * Iterator Classes - Javier
 > * Task Classes - Amirreza
 > * Manager Classes - Kunal
 > 
 > Left from previous sprint:
 > * Finalize methods being used in all classes
 > 
 > TODO for this sprint
 > * Once class methods are finalized, implementing and testing the creation of tasks will be prioritized. 
 > * Main Goals (implementation and testing):
 >    - Create a task
 >    - Create a task with subtasks
 >    - Edit a task
 >    - Remove a task
 >  * Additional:
 >     - Undo an edit, removal
 >     - Filter by piority, date, class
 >    
 > Bugs:
 > * Bugs will be worked on as encountered. We will need the basic functionality of task creation, removal, and editing prior to moving forward. 


 > ## Final deliverable
 > ### Final (mock) sprint:
 > * Create an option to allow users to edit existing tasks.
 > * Create an option to allow users to undo a previously made edit.
 > * Add additional functions to classes to make the above possible
 > * Fix issues found via valgrind

 
 ## Screenshots
 > ## Creation of a new classes to us in the creation of our tasks
 > ![ss1](https://github.com/cs100/final-project-kram003-ashir025-jhern571/blob/master/images/ss1.JPG)
 > ## Creation of three different tasks
 > ![ss2](https://github.com/cs100/final-project-kram003-ashir025-jhern571/blob/master/images/ss2.JPG)
 > ## Viewing tasks
 > ![ss3](https://github.com/cs100/final-project-kram003-ashir025-jhern571/blob/master/images/ss3.JPG)
 > ## Marking a task complete and printing resulting list
 > ![ss4](https://github.com/cs100/final-project-kram003-ashir025-jhern571/blob/master/images/ss4.JPG)
 > ## Creating a task list
 > ![ss5](https://github.com/cs100/final-project-kram003-ashir025-jhern571/blob/master/images/ss5.JPG)
 >  ## Viewing the task list
 >  ![ss6](https://github.com/cs100/final-project-kram003-ashir025-jhern571/blob/master/images/ss6.JPG)
 ## Installation/Usage
 > # Installation:
 > * Use cmake3 to make an executable for the task manager, and then run it using ./task_manager
 > # Navagating the task manager:
 > * You will be first prompted to create a class so that you may assign it to future tasks
 > * At this point, create additional classes (3) or begin creating tasks (1) or task lists (2)
 > * View created classes (5) and task lists (6) anytime
 > * View your created tasks (7) and specify how you would like to filter: date (d), class (c), priority (p)
 > * Once a task is complete, mark it as complete to no longer appear (4)
 > * Quit (q)
 ## Testing
 > Unit tests were created to test the Task classes. 
 > Valgrind was ran to narrow down memory leaks.
 > Testing the manager was difficult to test via unit tests due to its various private void functions. 
 > It was tested via the terminal as new functions were created and once all functions were finalized.  
 
