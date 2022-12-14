# Score-Browsing-System
Simple Score browsing system implemented on C++

## OVERVIEW

* The program will read the content of file "input.txt" that contains the grades of students and enable students to login and look their grades and grade statistics. It also has admin mode, when enabled, allows to modify the grades and other information of all students.

![demo](https://user-images.githubusercontent.com/62408255/195108942-d4d2a92c-b84a-413a-9f09-6f2d542b30ea.png)

### Description of commands

#### Login
* Allows students to sign in to the system if the information entered by student and information stored in system are identical.
* In the case of three consecutive unsuccsessful login attempts, the student will be blocked from further login attempts until admin will set a new passport.
* To login as an adminitrator, enter name: admin and password: admin.

#### Student Info
* Returns all information of student stored in the system such as name and grades.

#### Score Rank
* Returns the rank of student among all other students based on grade received for each HW and project.

#### Grade Statistic
* Returns the average and median scores of all students for all HWs and projects.

#### All Data
* Returns the list of all students along with their grades
* Can be only used by admin

#### Modify Info
* Allows to modify student's information such as name, password, and grades
* Includes simple checks to verify the strength of the new password. The password is assumed to be strong if it contains uppercase letters, lowercase letters, numbers, and punctuation characters.
* The grades can only be altered such that to fit in the allowed ranges for HWs and projects; the corresponding limits for grades are: HW1: 0 ~ 20, HW2: 0 ~ 30, PJ1: 0 ~ 100, PJ2: 0 ~ 100 
* Can be only used by admin

#### Add Student
* Allows to add a new studetn to the system. The input for this command must be student's name, password, and grades.
* Can be only used by admin

#### Logout
* Logs out of the user account. 

#### Terminate
* Terminates the system
