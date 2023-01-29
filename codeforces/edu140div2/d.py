def find_winning_integers(n, s):
  # Initialize the list of teams
  teams = []
  for i in range(2**n):
    teams.append((i + 1, [])) # Each team is represented as a tuple containing the skill level and a list of the games that the team has won
  # Iterate through the phases of the tournament
  for i in range(n):
    # Iterate through the games of the current phase
    for j in range(2**(n - i - 1)):
      # Determine the winner of the current game based on the value of s[i]
      if s[i] == "0":
        # In this phase, the team with the lower skill level wins
        if teams[j][0] < teams[j + 2**(n - i - 1)][0]:
          winner = teams[j]
          loser = teams[j + 2**(n - i - 1)]
        else:
          winner = teams[j + 2**(n - i - 1)]
          loser = teams[j]
      else:
        # In this phase, the team with the higher skill level wins
        if teams[j][0] > teams[j + 2**(n - i - 1)][0]:
          winner = teams[j]
          loser = teams[j + 2**(n - i - 1)]
        else:
          winner = teams[j + 2**(n - i - 1)]
          loser = teams[j]
      # Add the current game to the list of games won by the winning team
      winner[1].append(j)
      # Remove the losing team from the list
      teams.remove(loser)
  # Check if a team has won all the games in the tournament
  winning_integers = []
  for team in teams:
    if len(team[1]) == 2**n - 1:
      winning_integers.append(team[0])
  return winning_integers

# Test the function
print(find_winning_integers(3, "101")) # should print [4, 5, 6, 7]
# print(find_winning_integ
