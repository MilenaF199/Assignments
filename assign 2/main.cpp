/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

std::string kYourName = "Milena Flores"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream file(filename);
  std::set<std::string>aplicants;
  std::string aplicant;

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return aplicants;
}

  while (std::getline(file,aplicant)){
    aplicants.insert(aplicant);
  }

  file.close();
  return aplicants;
}


/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */

 std::string get_initials(const std::string& name){
  std::string initials;
  bool next_initial = true;

  for (char c: name){
    if (next_initial && isalpha(c)){
      initials += c;
      next_initial = true;
    }
    if (c= ' ') { 
      next_initial = true;
    }
  }

  return initials;
}

 std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> matches;
  std::string principal_initials = get_initials(name);

  for (const auto& student : students){
    if (get_initials(student) == principal_initials) { 
      matches.push(&student);
    }
  }

  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()){
    return "NO MATCHES FOUND. Better luck next year 😢";
  }

  srand(static_cast<unsigned int>(time(0)));
    int random_index = rand() % matches.size();

    for (int i = 0; i < random_index; ++i) {
        matches.push(matches.front()); 
        matches.pop();
    }

    const std::string* true_match = matches.front();
    matches.pop();
  
    return *true_match;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
