#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>

using namespace std;

class ChessBoard {
public:
	enum class Color { WHITE, BLACK };

	class Piece {
	public:
		Piece(Color color) : color(color) {}
		virtual ~Piece() {}

		Color color;
		string color_string() const {
			if (color == Color::WHITE) {
				return "white";
			} else {
				return "black";	
			} 
		}

		virtual std::string type() const = 0;

		virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

		virtual string symbol_string() const = 0;	
	};

	class King : public Piece {
	public:
		King(const Color color) : Piece(color) {}
		~King() {}

		string type() const override {
			return color_string() + " king";
		}

		bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
			bool valid_move;

			if (abs(from_x - to_x) > 1 || abs(from_y - to_y) > 1) {
				valid_move = false;
			} else {
				valid_move = true;
			}

			return valid_move;
		}

		string symbol_string() const override {
			if (color == Color::WHITE) {
				return "\u265A";
			} else {
				return "\u2654";
			}
		}
	};

	class Knight : public Piece {
	public:
		Knight(const Color color) : Piece(color) {}
		~Knight() {}

		string type() const override {
			return color_string() + " knight";
		}

		bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
			bool valid_move;

			if (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2) {
				valid_move = true;
			}
			else if (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1) {
				valid_move = true;
			}
			else {
				valid_move = false;
			}

			return valid_move;
		}

		string symbol_string() const override {
			if (color == Color::WHITE) {
				return "\u265E";
			} else {
				return "\u2658";
			}
		}
	};

	ChessBoard() {
		// Initialize the squares stored in 8 columns and 8 rows:
		squares.resize(8);
		for (auto &square_column : squares)
		{
			square_column.resize(8);
		}
	}

	void draw_board() {
			cout << "   A  B  C  D  E  F  G  H " << endl;
			for (int x = 0; x < 8; x++) {
				cout << (x + 1) << " ";
				for (int y = 0; y < 8; y++) {
					if (squares[y][x]) {
						cout << " " << squares[y][x] -> symbol_string() << " ";
					} else if ((x + y) % 2 == 0) {
						cout << "▒▒▒";
					} else {
						cout << "░░░";
					}

				}
				cout << endl;
			}
	}

	// 8x8 squares occupied by 1 or 0 chess pieces
  	vector<vector<unique_ptr<Piece>>> squares;

	/// Move a chess piece if it is a valid move.
	/// Does not test for check or checkmate.
	bool move_piece(const std::string &from, const std::string &to) {
		int from_x = from[0] - 'a';
		int from_y = stoi(string() + from[1]) - 1;
		int to_x = to[0] - 'a';
		int to_y = stoi(string() + to[1]) - 1;

		auto &piece_from = squares[from_x][from_y];
		if (piece_from) {
			if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
				cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
				auto &piece_to = squares[to_x][to_y];
				if (piece_to) {
					if (piece_from->color != piece_to->color) {
						cout << piece_to->type() << " is being removed from " << to << endl;
						if (auto king = dynamic_cast<King *>(piece_to.get()))
							cout << king->color_string() << " lost the game" << endl;
					} else {
						// piece in the from square has the same color as the piece in the to square
						cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
						return false;
					}
				}
				piece_to = move(piece_from);
				return true;
			} else {
				cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
				return false;
			}
		} else {
			cout << "no piece at " << from << endl;
			return false;
		}
	}	

};

int main() {

	ChessBoard board;

	board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
	board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
	board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

	board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
	board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
	board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

	vector<string> moves = {
		"e3", "e2",
		"e1", "e3",
		"b1", "b2",
		"e1", "e2",
		"g8", "h6",
		"b1", "c3",
		"h6", "g8",
		"c3", "d5",
		"g8", "h6",
		"d5", "f6",
		"h6", "g8",
		"f6", "e8"
	};

	board.draw_board();

	for(int i = 0; i < moves.size(); i += 2) {
		if (board.move_piece(moves[i], moves[i+1])) {
			board.draw_board();
			cout << "\n" << endl;
		}
	}
}
