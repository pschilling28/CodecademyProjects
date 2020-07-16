class Pokemon:
    def __init__(self, name, type, level = 5):
        self.name = name
        self.level = level
        self.type = type
        self.max_health = level * 5
        self.current_health = level * 5
        self.is_ko = False

    def __repr__(self):
        return "%s, a %s type Pokemon. It's at level %s, and has %i health out of a possible %i." % (self.name, self.type, self.level, self.current_health, self.max_health)

    def attack(self, target):
        if self.is_ko:
            print("A fainted Pokemon cannot attack. Switch your active Pokemon to continue.")
        elif self.type == "fire":
            print("%s uses %s attack on %s" % (self.name, self.type, target.name))
            if target.type == "grass":
                target.current_health -= self.level * 2
                print("Attack is super effective! %s takes %i damage." % (target.name, (self.level * 2)))
                if target.current_health <= 0:
                    target.faint()
            elif target.type == "water":
                target.current_health -= self.level / 2
                print("Attack is not very effective. %s takes %i damage." % (target.name, (self.level / 2)))
                if target.current_health <= 0:
                    target.faint()
            else:
                target.current_health -= self.level
                print("%s takes %i damage." % (target.name, self.level))
                if target.current_health <= 0:
                    target.faint()
        elif self.type == "grass":
            print("%s uses %s attack on %s" % (self.name, self.type, target.name))
            if target.type == "water":
                target.current_health -= self.level * 2
                print("Attack is super effective! %s takes %i damage." % (target.name, (self.level * 2)))
                if target.current_health <= 0:
                    target.faint()
            elif target.type == "fire":
                target.current_health -= self.level / 2
                print("Attack is not very effective. %s takes %i damage." % (target.name, (self.level / 2)))
                if target.current_health <= 0:
                    target.faint()
            else:
                target.current_health -= self.level
                print("%s takes %i damage." % (target.name, self.level))
                if target.current_health <= 0:
                    target.faint()
        elif self.type == "electric":
            print("%s uses %s attack on %s" % (self.name, self.type, target.name))
            if target.type == "water":
                target.current_health -= self.level * 2
                print("Attack is super effective! %s takes %i damage." % (target.name, (self.level * 2)))
                if target.current_health <= 0:
                    target.faint()
            else:
                target.current_health -= self.level
                print("%s takes %i damage." % (target.name, self.level))
                if target.current_health <= 0:
                    target.faint()
        else:
            print("%s uses %s attack on %s" % (self.name, self.type, target.name))
            target.current_health -= self.level
            print("%s takes %i damage." % (target.name, self.level))
            if target.current_health <= 0:
                target.faint()        



    def faint(self):
        self.is_ko = True
        print("%s fainted!" % self.name)


class Trainer:
    def __init__(self, name, pronoun, object_pronoun, possessive_pronoun, party):
        self.name = name
        self.pronoun = pronoun
        self.object_pronoun = object_pronoun
        self.possessive_pronoun = possessive_pronoun
        self.party = party
        self.active_pokemon = party[0]
        self.potion_ct = 3
    
    def __repr__(self):
        return "This Pokemon trainer's name is %s. %s has %i Pokemon in %s party, as well as %i potions on %s belt, and %s starting Pokemon is %s." % (self.name, self.pronoun, len(self.party), self.possessive_pronoun, self.potion_ct, self.possessive_pronoun, self.possessive_pronoun, self.active_pokemon.name)
    
    def use_potion(self, target):
        if self.potion_ct > 0:
            if target.current_health >= target.max_health - 20:
                target.current_health = target.max_health
                self.potion_ct -= 1
                print("%s healed to a full %i HP." % (target.name, target.current_health))
            elif target.current_health == target.max_health:
                print("%s already has full HP." % target.name)
            else:
                target.current_health += 20
                print("%s healed to %i HP." % (target.name, target.current_health))
        else:
            print("%s has no potions left!" % self.name)

    def switch_active_pokemon(self, switch_to):   
        if switch_to in self.party and switch_to.is_ko is False and switch_to != self.active_pokemon:
            self.active_pokemon = switch_to
            print("%s switches %s active Pokemon to %s" % (self.name, self.possessive_pronoun,self.active_pokemon))
        else:
            print("Choose a valid Pokemon from your party. It cannot be knocked out, the current active Pokemon, or one not in your party.")

    def fight(self, opponent):
        self.active_pokemon.attack(opponent.active_pokemon)

#Create Pokemon
charmander = Pokemon("Charmander", "fire")
bulbasaur = Pokemon("Bulbasaur", "grass")
squirtle = Pokemon("Squirtle", "water")
pikachu = Pokemon("Pikachu", "electric")
rattata = Pokemon("Rattata", "normal")
eevee = Pokemon("Eevee", "normal")

#Create trainer
pat = Trainer("Pat", "He", "him", "his", [bulbasaur, rattata, pikachu])
ashley = Trainer("Ashley", "She", "her", "her", [charmander, eevee, squirtle])

#Test code
#print(charmander)
#print(bulbasaur)
#print(squirtle)
#print(pikachu)
#print(rattata)
#print(eevee)
#print(pat)
#print(ashley)
#ashley.switch_active_pokemon()
#print(ashley.active_pokemon.name)

#Test Battle
print("%s sees %s in tall grass. %s attacks!" % (ashley.name, pat.name, ashley.name))
print("Trainer 1: %s" % pat)
print("Trainer 2: %s" % ashley)
ashley.fight(pat)
pat.fight(ashley)
ashley.fight(pat)
pat.fight(ashley)
ashley.fight(pat)
pat.switch_active_pokemon(rattata)
pat.fight(ashley)
ashley.fight(pat)
pat.fight(ashley)
ashley.fight(pat)
pat.fight(ashley)
ashley.use_potion(charmander)
