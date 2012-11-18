#!/usr/bin/env python

import sys

class PolandParser:
     """
     EXPR := '(' EXPR ')' | OP TERM TERM
     TERM := EXPR | NUM
     OP   := '+' | '-' | '*' | '/'
     NUM  := (any integer)
     """

     def __init__(self, line):
          """
          >>> parser = PolandParser('+ 1 (+ + 1 2 (* 3 4))')
          >>> parser.tokens
          ['+', '1', '(', '+', '+', '1', '2', '(', '*', '3', '4', ')', ')']
          """
          line = line.replace('(', ' ( ').replace(')', ' ) ')
          self.tokens = line.split()

     def run(self):
          """
          >>> parser = PolandParser('+ 1 (+ + 1 2 (* 3 4))')
          >>> parser.run()
          16
          >>> parser = PolandParser('(+ (+ 1 1) (+ 1 1))')
          >>> parser.run()
          4
          >>> parser = PolandParser('(+ (+ (- 99 11) (+ 11 11)) -111)')
          >>> parser.run()
          -1

          >>> parser = PolandParser('(+ (+ 1 1) (+ 1 1)')
          >>> parser.run()
          Traceback (most recent call last):
          Exception: tokens are insufficient
          """
          try:
               return self.parse_expr()
          except IndexError:
               raise Exception('tokens are insufficient')

     def parse_expr(self):
          """"
          >>> parser = PolandParser('(+ 7 5)')
          >>> parser.parse_expr()
          12
          >>> parser = PolandParser('+ 7 5')
          >>> parser.parse_expr()
          12

          >>> parser = PolandParser('(+ 7 5 ]')
          >>> parser.parse_expr()
          Traceback (most recent call last):
          Exception: unclosed parenthesis: ]

          >>> parser = PolandParser('7 5')
          >>> parser.parse_expr()
          Traceback (most recent call last):
          Exception: no operator: 7
          """
          token = self.tokens.pop(0)
          if token == '(':
               value = self.parse_expr()
               token2 = self.tokens.pop(0)
               if token2 == ')':
                    return value
               else:
                    raise Exception("unclosed parenthesis: %s" % token2)
          elif token == '+':
               term1 = self.parse_term()
               term2 = self.parse_term()
               return term1 + term2
          elif token == '-':
               term1 = self.parse_term()
               term2 = self.parse_term()
               return term1 - term2
          elif token == '*':
               term1 = self.parse_term()
               term2 = self.parse_term()
               return term1 * term2
          elif token == '/':
               term1 = self.parse_term()
               term2 = self.parse_term()
               return term1 / term2
          else:
               raise Exception("no operator: %s" % token)

     def parse_term(self):
          """"
          >>> parser = PolandParser('7')
          >>> parser.parse_term()
          7
          >>> parser = PolandParser('(+ 7 5)')
          >>> parser.parse_term()
          12
          """
          try:
               num = int(self.tokens[0])
               self.tokens.pop(0)
               return num
          except ValueError:
               return self.parse_expr()


if __name__ == '__main__':
     line = sys.stdin.readline().strip()
     parser = PolandParser(line)
     print parser.run()
