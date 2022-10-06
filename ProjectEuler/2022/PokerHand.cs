using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

// Problem 54 - Poker Hands

namespace SolveProblems
{
    public sealed class PokerHand
    {
        private enum Winner { Left, Right};
        private enum HandValue { HighCard = 0, OnePair, TwoPair, ThreeOfKind, Straight, Flush, FullHouse, FourOfKind, StraightFlush, RoyalFlush};
        private static string aceLow = "A123456789TJQK";
        private static string aceHigh = "123456789TJQKA";

        public static void Solve()
        {
            var count = 0;
            foreach (var line in File.ReadLines(@"C:/Code/WebProblems/ProjectEuler/input/poker.txt"))
            {
                var hands = ParseHands(line);
                var winner = CompareHands(hands.Item1, hands.Item2);
                if (winner == Winner.Left) count++;
            }

            Console.WriteLine($"The number of times player one wins is {count}");
        }

        private static Tuple<HashSet<Card>, HashSet<Card>> ParseHands(string line)
        {
            var cards = line.Split(' ');

            var hand1 = new HashSet<Card>();
            for (int i = 0; i < 5; ++i)
                hand1.Add(new Card(cards[i]));

            var hand2 = new HashSet<Card>();
            for (int i = 5; i < 10; ++i)
                hand2.Add(new Card(cards[i]));

            return new Tuple<HashSet<Card>, HashSet<Card>>(hand1, hand2);
        }

        private static Winner CompareHands(HashSet<Card> hand1, HashSet<Card> hand2) 
        {
            var hValue1 = GetHandValue(hand1);
            var hValue2 = GetHandValue(hand2);

            if (hValue1 == hValue2)
                return HigherCard(hand1, hand2);

            return hValue1 > hValue2 ? Winner.Left : Winner.Right;
        }

        private static HandValue GetHandValue(HashSet<Card> hand)
        {
            var value = IsHighCard(hand);

            var flush = value == HandValue.HighCard ? IsFlush(hand) : false;
            var straight = value == HandValue.HighCard ? IsStraight(hand) : false;

            return flush && straight ? IsRoyal(hand)
                : flush ? HandValue.Flush
                : straight ? HandValue.Straight
                : value;
        }

        private static HandValue IsRoyal(HashSet<Card> hand)
        {
            return hand.OrderBy(x => aceHigh.IndexOf(x.value)).Last().value == 'A' 
                ? HandValue.RoyalFlush : HandValue.StraightFlush;
        }

        private static bool IsFlush(HashSet<Card> hand)
        {
            var val = hand.First().suit;
            return hand.All(x => x.suit == val);
        }

        private static bool IsStraight(HashSet<Card> hand)
        {
            var lowStraight = CheckForStraight(hand, aceLow);
            var highStraight = CheckForStraight(hand, aceHigh);

            return lowStraight || highStraight;
        }

        private static bool CheckForStraight(HashSet<Card> hand, string customOrder)
        {
            var sorted = hand.OrderBy(x => customOrder.IndexOf(x.value));
            var first = customOrder.IndexOf(sorted.First().value);
            var last = customOrder.IndexOf(sorted.Last().value);

            return last - first == 4 ? true : false;
        }

        private static HandValue IsHighCard(HashSet<Card> hand)
        {
            var group = hand.GroupBy(x => x.value).OrderByDescending(x => x.Count());
            return group.Count() == 2 ? HandValue.FullHouse
                : group.Count() == 4 ? HandValue.OnePair
                : group.Count() == 5 ? HandValue.HighCard
                : group.Count() == 3 && group.First().Count() == 3 ? HandValue.ThreeOfKind
                : HandValue.TwoPair;
        }

        private static Winner HigherCard(HashSet<Card> hand1, HashSet<Card> hand2)
        {
            var desc1 = hand1.GroupBy(x => x.value).OrderByDescending(x => x.Count()).ThenByDescending(x => aceHigh.IndexOf(x.Key)).ToArray();
            var desc2 = hand2.GroupBy(x => x.value).OrderByDescending(x => x.Count()).ThenByDescending(x => aceHigh.IndexOf(x.Key)).ToArray();

            for (int i = 0; i < desc1.Length; ++i)
            {
                if (desc1[i] == desc2[i]) 
                    continue;

                return aceHigh.IndexOf(desc1[i].Key) > aceHigh.IndexOf(desc2[i].Key)
                    ? Winner.Left : Winner.Right;
            }

            return Winner.Left;
        }

        [DebuggerDisplay("{value.ToString()}{suit.ToString()}")]
        internal sealed class Card {
            public Card(string card)
            {
                value = card[0];
                suit = card[1];
            }

            public char suit;
            public char value;
        }
    }
}
