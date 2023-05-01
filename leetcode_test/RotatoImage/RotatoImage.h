#pragma once
#include<vector>
namespace RotatoImage {
	std::vector<std::vector<int>> Rotato(const std::vector<std::vector<int>>& image) {
		std::vector<std::vector<int>>	 res;
		res = image;
		std::reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); ++i) {
			for (int j = i + 1; j < res[i].size(); ++j)
				std::swap(res[i][j], res[j][i]);
		}
		return res;
	}
	std::vector<std::vector<int>> anti_Rotato(const std::vector<std::vector<int>>& image) {
		std::vector<std::vector<int>>	 res;
		res = image;
		for (int i = 0; i < res.size(); i++) {
			std::reverse(res.at(i).begin(),res.at(i).end());
		}
		for (int i = 0; i < res.size(); ++i) {
			for (int j = i + 1; j < res[i].size(); ++j)
				std::swap(res[i][j], res[j][i]);
		}
		return res;
	}
	std::vector<std::vector<int>> RotatoImage(const std::vector<std::vector<int>>& image) {
		std::vector<std::vector<int>>	 res = anti_Rotato(image);
		return res;
	};
}