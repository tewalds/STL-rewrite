#pragma once
#include <stddef.h>
#include <iostream>
#include <iterator>
#include <unistd.h>

namespace ehtesh {
    struct node {
        int* m_data;
        node* next;
        node* prev;
        node(int* data) {
            m_data = data;
            next = nullptr;
            prev = nullptr;
        }
        ~node() {
        }
    };

    std::ostream& operator<<(std::ostream &strm, const node& n){
        return strm << "Node(" << *n.m_data << ")";
    }

    struct list {
        size_t m_size;
        node* m_head;
        node* m_tail;
        list() {
            m_size = 0;
            m_head = nullptr;
            m_tail = nullptr;
        }
        ~list() {
            // TODO iterate through linked list and delete each element
            node* current = m_head;
            while (current) {
                std::cout << "~list(): " << *current << std::endl;
                current = current->next;
                usleep(1e5);
            }
        }

        // TODO make const
        void push_back(int* value) {
            node n = node(value);
            std::cout << "list.push_back(" << n << ")" << std::endl;
            if (m_size == 0){
                m_head = &n;
                m_tail = &n;
            }
            else if (m_size == 1){
                node* temp = m_tail;
                m_tail = &n;
                m_tail->next = temp;
            }
            else {
                node* temp = m_tail;
                m_tail = &n;
                m_tail->next = temp;
            }
            m_size++;
        }

    };
}