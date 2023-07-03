#include<iostream>
using namespace std;

class MataKuliah {
private:
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;

public:
    MataKuliah() {
        presensi = 0;
        activity = 0;
        exercise = 0;
        tugasAkhir = 0;
    }

    virtual float hitungNilaiAkhir() { return 0; }
    virtual void cekKelulusan() { return 0; }
	virtual void input() { return 0;}

	void setPresensi(float nilai) {
		this->presensi = nilai;
	}
	void setActivity(float nilai) {
		this->activity = nilai;
	}
	void setExercise(float nilai) {
		this->exercise = nilai;
	}
	void setTugasAkhir(float nilai) {
		this->tugasAkhir = nilai;
	}

	float getPresensi() {
		return presensi;
	}
	float getActivity() {
		return activity;
	}
	float getExercise() {
		return exercise;
	}
    float getTugasAkhir() {
        return tugasAkhir;
    }
	};

	class Pemrograman : public MataKuliah {
    private:
        float presensi;
        float activity;
        float exercise;
        float ujianAkhir;

    public:
        void setP(float p) {
            presensi = p;
        }

        void setA(float a) {
            activity = a;
        }

        void setE(float e) {
            exercise = e;
        }

        void setUA(float ua) {
            ujianAkhir = ua;
        }

        float getP() const {
            return presensi;
        }

        float getA() const {
            return activity;
        }

        float getE() const {
            return exercise;
        }

        float getUA() const {
            return ujianAkhir;
        };

        float getPresensi() const override {
            return getP();
        }

        float getActivity() const override {
            return getA();
        }

        float getExercise() const override {
            return getE();
        }

        float getUjianAkhir() const override {
            return getUA();
        }

        float getNilaiAkhir() const override {
            float nilaiAkhir = getPresensi() * 0.1 + getActivity() * 0.2 + getExercise() * 0.3 + getUjianAkhir() * 0.4;
            return nilaiAkhir;
        }
    };

    int main() {
        Pemrograman pemrograman;

        double presensi, activity, exercise, ujianAkhir;
        std::cout << "Masukkan nilai presensi: ";
        std::cin >> presensi;
        pemrograman.setP(presensi);

        std::cout << "Masukkan nilai activity: ";
        std::cin >> activity;
        pemrograman.setA(activity);

        std::cout << "Masukkan nilai exercise: ";
        std::cin >> exercise;
        pemrograman.setE(exercise);

        std::cout << "Masukkan nilai ujian akhir: ";
        std::cin >> ujianAkhir;
        pemrograman.setUA(ujianAkhir);

        float nilaiAkhir = pemrograman.getNilaiAkhir();

        std::cout << "Nilai Akhir: " << nilaiAkhir << std::endl;

        if (nilaiAkhir > 75) {
            std::cout << "Selamat! Anda lulus." << std::endl;
        }
        else {
            std::cout << "Maaf, Anda tidak lulus." << std::endl;
        }

        return 0;
    }