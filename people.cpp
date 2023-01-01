#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Person {
 public:
  Person(int id, std::string object_id, std::string first_name, std::string last_name,
         std::string birthplace, std::string affiliation_name)
      : id_(id),
        object_id_(object_id),
        first_name_(first_name),
        last_name_(last_name),
        birthplace_(birthplace),
        affiliation_name_(affiliation_name) {}

  int id() const { return id_; }
  std::string object_id() const { return object_id_; }
  std::string first_name() const { return first_name_; }
  std::string last_name() const { return last_name_; }
  std::string birthplace() const { return birthplace_; }
  std::string affiliation_name() const { return affiliation_name_; }

 private:
  int id_;
  std::string object_id_;
  std::string first_name_;
  std::string last_name_;
  std::string birthplace_;
  std::string affiliation_name_;
};

class AVLTree {
 public:
  AVLTree() : root_(nullptr) {}

  void Insert(const Person& value) {
    root_ = Insert(root_, value);
  }

  Person* Search(std::string object_id) {
    return Search(root_, object_id);
  }

 private:
  struct Node {
    Node(const Person& value) : value_(value), left_(nullptr), right_(nullptr) {}

    Person value_;
    Node* left_;
    Node* right_;
  };

  Node* root_;

  Node* Insert(Node* node, const Person& value) {
    if (node == nullptr) {
      return new Node(value);
    }

    if (value.object_id().compare(node->value_.object_id()) < 0) {
      node->left_ = Insert(node->left_, value);
    } else {
      node->right_ = Insert(node->right_, value);
    }

    return node;
  }

  Person* Search(Node* node, std::string object_id) {
    if (node == nullptr) {
      return nullptr;
    }

    if (node->value_.object_id().compare(object_id) == 0) {
      return &node->value_;
    }

    if (object_id.compare(node->value_.object_id()) < 0) {
      return Search(node->left_, object_id);
    } else {
      return Search(node->right_, object_id);
    }
  }
};

int main() {
  // Create an empty AVL tree
  AVLTree avl_tree;

  // Open the CSV file and read the records
  std::ifstream file("people.csv");
  std::string line;
  std::getline(file, line);  // Skip the header row
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string cell;
    std::vector<std::string> row;
    while (std::getline(ss, cell, ',')) {
      row.push_back(cell);
    }

    // Create a Person object from the row
    int id = std::stoi(row[0]);
    std::string object_id = row[1];
    std::string first_name = row[2];
    std::string last_name = row[3];
    std::string birthplace = row[4];
    std::string affiliation_name = row[5];
    Person person(id, object_id, first_name, last_name, birthplace, affiliation_name);

    // Insert the person into the AVL tree
    avl_tree.Insert(person);
  }

  // Search for a person by object_id
  std::string object_id;
  std::cout << "Enter object_id to search for: ";
  std::cin >> object_id;

  Person* result = avl_tree.Search(object_id);
  if (result != nullptr) {
    std::cout << "Found person: " << result->first_name() << " " << result->last_name() << std::endl;
  } else {
    std::cout << "Person not found" << std::endl;
  }

  return 0;
}

