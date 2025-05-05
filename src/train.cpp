// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

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
  if (!first) {
    return 0;
  }
  Car* current = first;
  int steps = 0;
  current->light = true;
  do {
    current = current->next;
    steps++;
    countOp++;
  } while (!current->light && current != first);
  if (current->light) {
    current->light = false;
    for (int i = 0; i < steps; i++) {
      current = current->prev;
      countOp++;
    }
    if (!current->light) {
      return steps;
    } else {
      return getLength();
    }
  }
  return steps;
}

int Train::getOpCount() {
    return countOp;
}
