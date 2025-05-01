// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (first) {
    Car* current = first;
    do {
      Car* next = current->next;
      delete current;
      current = next;
    } while (current != first);
  }
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;
  int length = 0;
  Car* current = first;
  do {
    countOp++;
    length++;
    current = current->next;
  } while (current != first);
  return length;
}

int Train::getOpCount() {
    return countOp;
}
